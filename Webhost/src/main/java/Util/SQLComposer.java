package Util;

/**
 * Created by Andras on 13/04/2016.
 */
public interface SQLComposer
{
	String GetTripQuery( String aDateTime, String aAirline, String aAirportFrom, String aAirportTo, String aCurrency );
}
