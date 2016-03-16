package PageGuest;

/**
 * Created by andras.igneczi on 16/03/2016.
 */
public class SearchStateSearching extends SearchState
{
    @Override
    public void doAction( WebPageGuest aWebPageGuest )
    {
        mWebPageGuest = aWebPageGuest;
        aWebPageGuest.setSearchState( this );
    }

    public String toString()
    {
        return "SearchStateSearching";
    }
}