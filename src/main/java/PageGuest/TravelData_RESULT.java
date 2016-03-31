package PageGuest;

import java.util.ArrayList;

public class TravelData_RESULT
{
	public static class TravelData_PossibleTrips
	{
		public String mDepartureDaytime;    // 2016.03.25 17:10
		public String mArrivalDaytime;      // 2016.03.25 22:10
		public String mPrices_BasicFare_Normal;
		public String mPrices_BasicFare_Discount;
		public String mPrices_PlusFare_Normal;
		public String mPrices_PlusFare_Discount;
		public boolean mOutboundTrip;
	}

	public TravelData_RESULT()
	{
		mTrips = new ArrayList<TravelData_PossibleTrips>();
	}

	public String mAirline;
	public String mAirportCode_LeavingFrom;   // SOF
	public String mAirportCode_GoingTo;       // HHN
	public ArrayList<TravelData_PossibleTrips> mTrips;
	public boolean mReturnTicket;

	String toString( TravelDataResultComposer aComposer )
	{
		if( aComposer != null )
			return aComposer.toFormattedString();
		return super.toString();
	}
}