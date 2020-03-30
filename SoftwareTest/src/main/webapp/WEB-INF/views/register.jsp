<%@ page language="java" contentType="text/html; charset=UTF-8"
		 pageEncoding="UTF-8"%>

<html>
<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
	<title>注册</title>
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
			<div class="layui-form-mid"><span class="title-center">注册</span></div>
		</div>
	</div>
	<div class="layui-form-item">
		<label class="layui-form-label">账号</label>
		<div class="layui-input-inline">
			<input type="text" id="userId" name="userId" required  lay-verify="required" placeholder="请输入账号" autocomplete="off" class="layui-input">
		</div>
	</div>
	<div class="layui-form-item">
		<label class="layui-form-label">密码</label>
		<div class="layui-input-inline">
			<input type="password" id="password" name="password" required lay-verify="required" placeholder="请输入密码" autocomplete="off" class="layui-input">
		</div>
	</div>
	<div class="layui-form-item">
		<div class="layui-input-block">
			<button class="layui-btn" lay-submit lay-filter="formDemo">确定</button>
			<button type="reset" class="layui-btn">重置</button>
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
			// 账号密码正则表达式验证
			var username_regex = /^(?=.*?[a-z)(?=.*>[A-Z])(?=.*?[0-9])[a-zA_Z0-9]{5,10}$/;
			var password_regex = /^(?=.*?[a-z)(?=.*>[A-Z])(?=.*?[0-9])[a-zA_Z0-9]{6,10}$/;
			var username = $("#userId").val();
			var password = $("#password").val();

			if (!username_regex.test(username) || !password_regex.test(password)){
				layer_alert("用户名由5~10位字母和数字组成，密码由6~10位字母和数字组成，请输入正确的用户名或密码！");
				return false;
			}

			$.post(
					"/register",
					data.field,
					function (data) {
						if (data.result == '1'){
							layer.open({
								title: '提示',
								content: "注册成功！",
								yes: function(index, layero){
									window.location.href = '/page_login';
								}
							});

						}else{
							layer_alert(data.message);
							return false;
						}
					}
			)
			return false;
		});
	});
</script>
</body>
</html>