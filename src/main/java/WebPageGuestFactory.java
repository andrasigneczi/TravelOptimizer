import PageGuest.*;

/**
 * Created by Andras on 15/03/2016.
 */
public class WebPageGuestFactory
{
	public static WebPageGuest Create( String PageType )
	{
		if( PageType.equalsIgnoreCase( "wizzair" ))
		{
			return new WizzAirPageGuest();
		}
		else if( PageType.equalsIgnoreCase( "ryanair" ))
		{
			return new RyanAirPageGuest();
		}
		else if( PageType.equalsIgnoreCase( "momondo" ))
		{
			return new MomondoPageGuest();
		}
		else if( PageType.equalsIgnoreCase( "flibco" ))
		{
			return new FlibcoPageGuest();
		}
		else if( PageType.equalsIgnoreCase( "bulgarianair" ))
		{
			return new BulgarianAirPageGuest();
		}
		else if( PageType.equalsIgnoreCase( "booking" ))
		{
			return new BookingDotComPageGuest();
		}
		return null;
	}
}