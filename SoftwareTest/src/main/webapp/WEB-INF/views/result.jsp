<%--
  Created by IntelliJ IDEA.
  User: Me
  Date: 2019/10/27
  Time: 23:36
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>搜索结果</title>
</head>
<body>
<c:forEach var="info" items="${infos}">
    <h5>标题： ${info.name}</h5>
    <h5>内容： ${info.summary}</h5>
    <h5>图片： </h5>
    <img src="${info.images[0].url}">
    <a href="/${info.id}/detail">查看详细</a>
</c:forEach>
</body>
</html>
