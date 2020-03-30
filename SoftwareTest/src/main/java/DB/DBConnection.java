package DB;

import utils.DBConnect;

import java.sql.Connection;
import java.sql.DriverManager;
import java.util.Properties;

public class DBConnection {
  private static final Connection connection = null;
  public static Connection connection()
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
    String Driver = properties.getProperty("driver");
    String USER = properties.getProperty("user");
    String PASSWORD = properties.getProperty("password");
    String URL = properties.getProperty("url");


    Connection connection = null;
    try{
      Class.forName(Driver);
      connection= DriverManager.getConnection(URL,USER,PASSWORD);
    }catch(Exception e){
      System.out.println("mysql驱动加载失败！");
    }
    return connection;
  }

  //关闭连接
  public static void closeConnection(){
    try {
      connection.close();
    }catch (Exception e){
      System.out.println("关闭数据库失败");
    }
  }
}
