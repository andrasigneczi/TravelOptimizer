package PageGuest;

/**
 * Created by Andras on 15/03/2016.
 */
public class BookingDotComPageGuest extends WebPageGuest
{
	public BookingDotComPageGuest()
	{
		super("booking.com", "http://www.booking.com");
	}

	public void DoSearch(String aFrom, String aTo, String aDepartureDate, String aReturnDate )
	{
	}

	public void DoSearchByAirportName( String aAirportName_Way_From, String aAirportName_Way_To,
	                                   String aDepartureDate_Way_To, String aReturnDate_Way_Back )
	{

	}

	public void DoSearchFromConfig()
	{

	}

	@Override
	public void stop()
	{

	}
}