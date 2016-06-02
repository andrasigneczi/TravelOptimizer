package Util;

import org.springframework.beans.factory.annotation.Autowire;
import org.springframework.context.annotation.Bean;

import java.lang.annotation.Annotation;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Scanner;

/**
 * Created by Andras on 29/05/2016.
 */
public class ChartBuilder
{
	private final String mHtmlTemplate;
	private final String mJsTemplate;
	private final String mDivTemplate;
	private final String mSeriesTemplate;

	private String mSelectedDepartureAirport = "-";
	private String mSelectedArrivalAirport   = "-";
	private boolean mReturnCheckboxChecked   = false;
	private OneWayTrip mToggledButton = null;

	public ChartBuilder()
	{
		Scanner lScanner  = new Scanner(getClass().getClassLoader().getResourceAsStream("charts_template.html" ), "UTF-8" );
		mHtmlTemplate = lScanner.useDelimiter( "\\A" ).next();
		lScanner.close();

		lScanner  = new Scanner(getClass().getClassLoader().getResourceAsStream("charts_template.js" ), "UTF-8" );
		mJsTemplate = lScanner.useDelimiter( "\\A" ).next();
		lScanner.close();

		mDivTemplate = "<div id=\"[CONTAINER]\" style=\"min-width: 310px; height: 400px; margin: 0 auto\"></div>";
		mSeriesTemplate = "{\n" +
				"                name: '[SERIES.NAME]',\n" +
				"                type: '[TYPE.NAME]',\n" +
				"                data: [\n" +
				"                [SERIES.DATA]\n" +
				"                ]\n" +
				"            }";
	}

	public String getSelectedDepartureAirport()
	{
		return mSelectedDepartureAirport;
	}

	public void setSelectedDepartureAirport( String aSelectedDepartureAirport )
	{
		this.mSelectedDepartureAirport = aSelectedDepartureAirport;
	}

	public String getSelectedArrivalAirport()
	{
		return mSelectedArrivalAirport;
	}

	public void setSelectedArrivalAirport( String aSelectedArrivalAirport )
	{
		this.mSelectedArrivalAirport = aSelectedArrivalAirport;
	}

	public boolean isReturnCheckboxChecked()
	{
		return mReturnCheckboxChecked;
	}

	public void setReturnCheckboxChecked( boolean aReturnCheckboxChecked )
	{
		this.mReturnCheckboxChecked = aReturnCheckboxChecked;
	}

	public OneWayTrip getToggledButton()
	{
		return mToggledButton;
	}

	public void setToggledButton( OneWayTrip aToggledButton )
	{
		this.mToggledButton = aToggledButton;
	}

	private String IsoDatetimeToEngDate( String aDateTime )
	{
		//String lDate = aDateTime.substring( 0, 10 );
		/*
		StringBuffer lReturn = new StringBuffer();
		IntStream
				.range( 0, lDate.length() - 1 )
				.forEach( s -> lReturn.append( lDate.charAt( lDate.length() - 1 - s ) ) );
		*/
		LocalDateTime lLocalDateTime = LocalDateTime.parse(aDateTime, DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm"));
		return String.format( "%02d.%02d.%04d %02d:%02d", lLocalDateTime.getDayOfMonth(),
				lLocalDateTime.getMonthValue(), lLocalDateTime.getYear(), lLocalDateTime.getHour(), lLocalDateTime.getMinute() );
	}

	/**
	 *
	 * @param aDateTime1      first trip's departure day
	 * @param aDateTime2      return trip's departure day
	 * @param aAirline        airline
	 * @param aAirportFrom    departure airport
	 * @param aAirportTo      arrival airport
	 * @param aCurrency       currency of the tickets' price
	 * @param aHtmlTagId      a string for the modal window
	 * @param aOneWay         one way or return ticket
	 * @return String [], first element the div of the chart, second element the javascript of the chart
	 */
	private String [] GetHtmlContent( final String aDateTime1, final String aDateTime2,
	                                  final String aAirline, final String aAirportFrom,
	                                  final String aAirportTo, final String aCurrency,
	                                  final String aHtmlTagId, final boolean aOneWay,
	                                  final ArrayList<TravelData_INPUT.BoughtTicket> aBoughtTickets,
	                                  final ArrayList<TravelData_INPUT.Discount> aDiscounts )
	{
		HighChartDataResultComposer lHighChartDataResultComposerOutbound = new HighChartDataResultComposer();
		Hashtable<String,String> lResult1 = SQLiteDataProvider.getInstance().GetTripData( aDateTime1/*2016-07-16 06:30*/, aAirline, aAirportFrom, aAirportTo, aCurrency, lHighChartDataResultComposerOutbound );
		String lDate1 = IsoDatetimeToEngDate( aDateTime1 );
		String lSeries1 = mSeriesTemplate.replace( "[SERIES.NAME]", lDate1 )
				.replace( "[TYPE.NAME]", "line" )
				.replace( "[SERIES.DATA]", lResult1.get( "Result" ) );

		String lAirportFrom = aAirportFrom;
		if( aAirportFrom.equals( "-" ))
			lAirportFrom = lResult1.get( "AirportCode_LeavingFrom" );

		String lAirportTo = aAirportTo;
		if( aAirportTo.equals( "-" ))
			lAirportTo = lResult1.get( "AirportCode_GoingTo" );

		if( aBoughtTickets != null )
		{
			for( TravelData_INPUT.BoughtTicket lTicket : aBoughtTickets )
			{
				HighChartDataResultComposer lHCDRCExtra = new HighChartDataResultComposer();
				lHCDRCExtra.add( lTicket.mDatetime, lTicket.mPrice, "%" );
				String lSeries = mSeriesTemplate.replace( "[SERIES.NAME]", lTicket.mName )
						.replace( "[TYPE.NAME]", "line" )
						.replace( "[SERIES.DATA]", lHCDRCExtra.getResult() );
				lSeries1 += ",\n" + lSeries;
			}
		}

		if( aDiscounts != null )
		{
			for( TravelData_INPUT.Discount lDiscount : aDiscounts )
			{
				HighChartDataResultComposer lHCDRCExtra = new HighChartDataResultComposer();
				lHCDRCExtra.add( lDiscount.mBeginning, "100", "%" );
				lHCDRCExtra.add( lDiscount.mEnding, "100", "%" );
				String lSeries = mSeriesTemplate.replace( "[SERIES.NAME]", lDiscount.mName )
						.replace( "[TYPE.NAME]", "area" )
						.replace( "[SERIES.DATA]", lHCDRCExtra.getResult() );
				lSeries1 += ",\n" + lSeries;
			}
		}

		String lJS;
		if( !aOneWay )
		{
			HighChartDataResultComposer lHighChartDataResultComposerReturn = new HighChartDataResultComposer();
			Hashtable<String,String> lResult2 = SQLiteDataProvider.getInstance().GetTripData( aDateTime2/*2016-07-19 08:30*/, aAirline, aAirportTo, aAirportFrom, aCurrency, lHighChartDataResultComposerReturn );
			String lDate2 = IsoDatetimeToEngDate( aDateTime2 );
			String lSeries2 = mSeriesTemplate.replace( "[SERIES.NAME]", lDate2 )
					.replace( "[TYPE.NAME]", "line" )
					.replace( "[SERIES.DATA]", lResult2.get( "Result" ) );

			HashSet<String> lFoundCurrency = lHighChartDataResultComposerReturn.getFoundCurrency();
			String lCurrency = aCurrency;
			if( aCurrency.equals( "%" ) && !lFoundCurrency.isEmpty())
				lCurrency = lFoundCurrency.iterator().next();

			String lSumResult = lHighChartDataResultComposerOutbound.Summarize( lHighChartDataResultComposerReturn );
			String lSeries3 = mSeriesTemplate.replace( "[SERIES.NAME]", "Sum" )
					.replace( "[TYPE.NAME]", "line" )
					.replace( "[SERIES.DATA]", lSumResult );

			lJS = mJsTemplate.replace( "[TITLE]", lDate1 + " - " + lDate2 + " " + lAirportFrom + " - " + lAirportTo )
					.replace( "[SUBTITLE]", aAirline )
					.replace( "[DEVIZA]", lCurrency )
					.replace( "[SERIES]", lSeries1 + ",\n" + lSeries2 + ",\n" + lSeries3 )
					.replace( "[CONTAINER]", aHtmlTagId );
			String lDiv = mDivTemplate.replace( "[CONTAINER]", aHtmlTagId );
			return new String[] { lDiv, lJS };
		}
		else
		{
			HashSet<String> lFoundCurrency = lHighChartDataResultComposerOutbound.getFoundCurrency();
			String lCurrency = aCurrency;
			if( aCurrency.equals( "%" ) && !lFoundCurrency.isEmpty())
				lCurrency = lFoundCurrency.iterator().next();

			lJS = mJsTemplate.replace( "[TITLE]", lDate1 + " " + lAirportFrom + " - " + lAirportTo )
					.replace( "[SUBTITLE]", aAirline )
					.replace( "[DEVIZA]", lCurrency )
					.replace( "[SERIES]", lSeries1 )
					.replace( "[CONTAINER]", aHtmlTagId );
		}
		String lDiv = mDivTemplate.replace( "[CONTAINER]", aHtmlTagId );
		return new String[] { lDiv, lJS };
	}

	public String GenerateHtmlContentUsingConfig()
	{
		ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
		String lScriptCotent = "";
		String lDivContent = "";
		int lContainerIndex = 0;
		for( TravelData_INPUT lTDI : lSearchList )
		{
			if( !lTDI.mAirline.equals( "wizzair" ) && !lTDI.mAirline.equals( "ryanair" ))
				continue;

			lTDI.mReturnTicket = ( lTDI.mReturnDatetime.length() != 0 );
			String[] lContent = GetHtmlContent( lTDI.mDepartureDatetime, lTDI.mReturnDatetime, lTDI.mAirline,
					lTDI.mAirportCode_LeavingFrom, lTDI.mAirportCode_GoingTo,
					lTDI.mCurrency, "container" + lContainerIndex++, !lTDI.mReturnTicket,
					lTDI.mBoughtTickets, lTDI.mDiscounts );
			lScriptCotent += lContent[ 1 ];
			lDivContent += lContent[ 0 ];
		}
		String  lHtml = mHtmlTemplate.replace( "[CHART_SCRIPTS]", lScriptCotent )
				.replace( "[CHART_DIVS]", lDivContent );

		String lGetCollectedDepartureDateList = SQLiteDataProvider.getInstance().GetCollectedDepartureDateList( new HtmlListFormatterButtonList(),
				mSelectedDepartureAirport, mSelectedArrivalAirport, mReturnCheckboxChecked );
		lHtml = lHtml.replace( "[AVAILABLE_TRIPS]", lGetCollectedDepartureDateList );

		String lDepartureAirportSelector = SQLiteDataProvider.getInstance().GetDepartureAirportList( new HtmlListFormatterSelect( "DepartureAirportList" ),
				mSelectedDepartureAirport);
		lHtml = lHtml.replace( "[DEPARTURE_AIRPORTS]", lDepartureAirportSelector );

		String lArrivalAirportSelector = SQLiteDataProvider.getInstance().GetArrivalAirportList( new HtmlListFormatterSelect( "ArrivalAirportList" ),
				mSelectedDepartureAirport, mSelectedArrivalAirport);
		lHtml = lHtml.replace( "[ARRIVAL_AIRPORTS]", lArrivalAirportSelector );

		return lHtml;
	}

	public String DateTimeButtonPushed( String aParam )
	{
		String[] lValues = aParam.split( "\\|" );
		// lValues = airline, leavingfrom, goingto, outbound, datetime
		OneWayTrip lTB = new OneWayTrip(
				lValues[ 4 ], lValues[ 0 ],
				lValues[ 1 ], lValues[ 2 ],
				Boolean.parseBoolean( lValues[ 3 ] ));

		if( mReturnCheckboxChecked )
		{
			if( mToggledButton != null )//if( a button already pushed )
			{
				if( mToggledButton.equals( lTB ))
				{ // if the toggled button was pushed again
					mToggledButton = null;
				}
				else
				{
					//  with the second button we have a return trip, display it
					String[] lHtmlContent = GetHtmlContent( mToggledButton.getDatetime(), lTB.getDatetime(), lTB.getAirline(),
							mToggledButton.getOutboundDepartureAirport(), mToggledButton.getOutboundArrivalAirport(),
							"%", "modalcontainer", false, null, null );
					return lHtmlContent[ 0 ] + "<script>" + lHtmlContent[ 1 ] + "</script>";
				}
			}
			else
			{
				//  this is the first button, toggle it!
				mToggledButton = lTB;
				String lGetCollectedDepartureDateList = SQLiteDataProvider.getInstance().GetCollectedDepartureDateList( new HtmlListFormatterButtonList( mToggledButton ),
						lTB.getOutboundDepartureAirport(), lTB.getOutboundArrivalAirport(), mReturnCheckboxChecked );
				return lGetCollectedDepartureDateList;
			}
			// recolor or filter the buttons
		}
		else
		{
			String[] lHtmlContent = GetHtmlContent( lTB.getDatetime(), "", lTB.getAirline(),
					lTB.getOutboundDepartureAirport(), lTB.getOutboundArrivalAirport(),
					"%", "modalcontainer", true, null, null );
			return lHtmlContent[ 0 ] + "<script>" + lHtmlContent[ 1 ] + "</script>";
		}
		return null;
	}
}