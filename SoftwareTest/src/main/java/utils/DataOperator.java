package utils;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.servlet.http.HttpServletRequest;

import com.sun.javafx.fxml.BeanAdapter;

import entity.Visitor;

public class DataOperator {

	public int CheckVisitorExists(Map<String, Object> params) {
		String username = params.get("username").toString();
		String password = params.get("password").toString();
		Visitor visitor = new Visitor();
		visitor.setUsername(username);
		visitor.setPassword(password);
		DBConnect dbConnect = new DBConnect();
		try {
			Connection connection = dbConnect.getConnection();
			PreparedStatement preparedStatement2 = connection
					.prepareStatement("select * from user_tab where username=? and password=?");
			preparedStatement2.setString(1, username);
			preparedStatement2.setString(2, password);
			ResultSet resultSet = preparedStatement2.executeQuery();
			if (resultSet.next()) {
				connection.close();
				preparedStatement2.close();
				resultSet.close();
				return 1;
			} else {
				connection.close();
				preparedStatement2.close();
				resultSet.close();
				return 0;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return 0;
	}

	public boolean UserInfoCorrect(Visitor visitor) {
		String name = visitor.getUsername();
		String pass = visitor.getPassword();

		if (name.length() < 5 | name.length() > 10) {
			return false;
		}
		if (pass.length() < 6 | pass.length() > 10) {
			return false;
		}
/*		Pattern pattern = Pattern.compile("/^(?=.*?[a-z)(?=.*>[A-Z])(?=.*?[0-9])[a-zA_Z0-9]{6,10}$/");
		Matcher matcher = pattern.matcher(pass);
		if(!matcher.matches()) {
			return false;
		}*/
		return true;
	}

	// 状态码2用户已存在 1用户添加成功 0用户添加失败
	public int AddVisitor(Map<String,Object> params) throws Exception {
		String username = params.get("userId").toString();
		String password = params.get("password").toString();
		Visitor visitor = new Visitor();
		visitor.setUsername(username);
		visitor.setPassword(password);
		if (!UserInfoCorrect(visitor))// 如果用户信息不符合要求则添加用户失败
		{
			return 0;
		}
		DBConnect dbConnect = new DBConnect();
		Connection connection = dbConnect.getConnection();
		PreparedStatement preparedStatement2 = connection.prepareStatement("select * from user_tab where username=?");
		preparedStatement2.setString(1, username);
		ResultSet resultSet = preparedStatement2.executeQuery();
		// 为true时说明用户信息在数据库中存在
		if (resultSet.next()) {
			resultSet.close();
			preparedStatement2.close();
			connection.close();
			return 2;
		}
		PreparedStatement preparedStatement = connection
				.prepareStatement("insert into user_tab(username,password) values(?,?)");
		preparedStatement.setString(1, username);
		preparedStatement.setString(2, password);
		if (preparedStatement.executeUpdate() > 0) {
			preparedStatement.close();
			connection.close();
			dbConnect.closeAll();
			return 1;
		}
		return 0;
	}
}
