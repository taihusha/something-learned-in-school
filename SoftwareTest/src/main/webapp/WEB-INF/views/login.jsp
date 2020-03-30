<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
    <title>登录</title>
    <meta name="description" content="登录界面">
    <meta name="keywords" content="登录界面">
    <link href="${pageContext.request.contextPath}/layui/css/layui.css" rel="stylesheet" type="text/css" />
    <script type="text/javascript" src="${pageContext.request.contextPath}/js/jquery-1.11.2.min.js"></script>
    <script type="text/javascript" src="${pageContext.request.contextPath}/js/common.js"></script>

    <style type="text/css">
        .position{
            width: 400px;
            height: 250px;
            background: #FFF;
            margin: 200px auto;
            position: relative;
        }
        .title-center{
            font-size: 21px;
        }
    </style>
</head>
<body>
<form class="layui-form position layui-bg-cyan" method="post">
    <div class="layui-form-item">
        <label class="layui-form-label"></label>
        <div class="layui-input-inline">
            <div class="layui-form-mid"><span class="title-center">登录</span></div>
        </div>
    </div>
    <div class="layui-form-item">
        <label class="layui-form-label">账号</label>
        <div class="layui-input-inline">
            <input type="text" name="username" required  lay-verify="required" placeholder="请输入账号" autocomplete="off" class="layui-input">
        </div>
    </div>
    <div class="layui-form-item">
        <label class="layui-form-label">密码</label>
        <div class="layui-input-inline">
            <input type="password" name="password" required lay-verify="required" placeholder="请输入密码" autocomplete="off" class="layui-input">
        </div>
    </div>
    <div class="layui-form-item">
        <div class="layui-input-block">
            <button class="layui-btn" lay-submit lay-filter="formDemo">登录</button>
            <button type="button" class="layui-btn" onclick="my_register()">注册</button>
        </div>
    </div>
</form>

<script type="text/javascript" src="${pageContext.request.contextPath}/layui/layui.all.js"></script>
<script>
    //Demo
    layui.use('form', function(){
        var form = layui.form;

        //监听提交
        form.on('submit(formDemo)', function(data){
            $.post(
                "/login",
                data.field,
                function (data) {
                    if (data.result == '1'){
                        window.location.href = '/index';
                    }else{
                        layer_alert(data.message);
                        return false;
                    }
                }
            )
            return false;
        });
    });

    function my_register() {
        window.location.href='/page_register';
    }
</script>
</body>
</html>