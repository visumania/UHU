package Modelo;

import java.util.Date;

public class Tweet 
{
    String id;
    String username;
    int followers;
    String text;
    String language; 
    Date date;
    
    public Tweet()
    {
        this.id = null;
        this.username = null;
        this.followers = 0;
        this.text = null;
        this.language = null;
        this.date = null;
    }
    
    public Tweet(String id, String username, int followers, String text, String language, Date date)
    {
        this.id = id;
        this.username = username;
        this.followers = followers;
        this.text = text; 
        this.language = language;
        this.date = date;
    }
    
    public String getId() 
    {
        return id;
    }

    public void setId(String id) 
    {
        this.id = id;
    }

    public String getUsername() 
    {
        return username;
    }

    public void setUsername(String username) 
    {
        this.username = username;
    }

    public int getFollowers() 
    {
        return followers;
    }

    public void setFollowers(int followers) 
    {
        this.followers = followers;
    }

    public String getText() 
    {
        return text;
    }

    public void setText(String text) 
    {
        this.text = text;
    }
    
    public String getLanguage() 
    {
        return language;
    }

    public void setLanguage(String language) 
    {
        this.language = language;
    }

    public Date getDate() 
    {
        return date;
    }

    public void setDate(Date date) 
    {
        this.date = date;
    }
}
