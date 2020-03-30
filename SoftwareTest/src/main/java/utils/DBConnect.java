package utils;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Properties;

public class DBConnect
{
	private static String Driver = "";
	private static String USER;
	private static String PASSWORD;
	private static String URL;
	private Connection connection = null;
	private Statement statement = null;
	private ResultSet rs = null;

	public DBConnect()// 构造函数中通过配置文件加载数据库连接信息
	{
		Properties properties = new Properties();
		try
		{
			properties.load(DBConnect.class.getResourceAsStream("/database-info.properties"));// 读取被指文件，将其以流的形式读入
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		Driver = properties.getProperty("driver");
		USER = properties.getProperty("user");
		PASSWORD = properties.getProperty("password");
		URL = properties.getProperty("url");
	}

	public Connection getConnection() throws IOException// 获取数据库连接驱动以及连接数据库
	{

		try
		{
			Class.forName(Driver);
		}
		catch (ClassNotFoundException e)
		{
			e.printStackTrace();
		}
		try
		{
			connection = DriverManager.getConnection(URL, USER, PASSWORD);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		return connection;
	}

	public void closeAll()// 关闭结果集、查询执行、数据库连接
	{
		if (statement != null)
		{
			try
			{
				statement.close();
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
		if (connection != null)
		{
			try
			{
				connection.close();
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
		if (rs != null)
		{
			try
			{
				rs.close();
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
	}
	
	public static void main(String[] args)
	{
		DBConnect dbConnect=new DBConnect();
		try {
			System.out.println(dbConnect.getConnection());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		dbConnect.closeAll();
	}
}
