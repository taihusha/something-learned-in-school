<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>文艺青年篇-首页</title>
    <link rel="stylesheet" type="text/css" href="<%=path%>/css/style1536672475627.css">
    <link href="<%=path%>/css/index.css" rel="stylesheet" type="text/css">
    <link href="<%=path%>/css/gonglve.css" rel="stylesheet" type="text/css">
    <link href="<%=path%>/css/detail_mdd.css" rel="stylesheet" type="text/css">
</head>
<body style="position: relative;">

<div id="header" xmlns="http://www.w3.org/1999/html">
    <div class="mfw-header">
        <div class="header-wrap clearfix" id="_j_head_nav_warper">
            <div class="head-logo"><a class="mfw-logo" title="马蜂窝自由行" href="/index"></a></div>
            <div class="login-out">
                <c:choose>
                    <c:when test="${sessionScope.username == null}">
                        <a id="_j_showlogin" title="登录" href="/page_login" rel="nofollow">登录</a><span
                            class="split">|</span><a href="/page_register" title="注册帐号"
                                                     rel="nofollow">注册</a>
                    </c:when>
                    <c:otherwise>
                        <a id="_j_showlogin" title="用户名" rel="nofollow">${sessionScope.username}</a>
                        <span class="split">|</span><a href="/exit" title="注销帐号"
                                                       rel="nofollow">注销</a>
                    </c:otherwise>
                </c:choose>
            </div>
        </div>
        <div class="shadow"></div>
    </div>

</div>

<style type="text/css">
    .m-t-20 {
        margin-top: 20px;
    }

    .m-t-40 {
        margin-top: 40px;
    }
</style>
<div class="wrapper">
    <div class="focus">
        <div class="mdd_nav">
            <form id="search_form" method="post" action="/index">
                <div class="input_like">
                    <div>
                        <span style="cursor:pointer" onclick="inputSearch()"></span>
                        <input id="search_word" name="search_word" type="text" placeholder="请输入想去的武汉景点" value="${search_word}">
                        <div class="clear"></div>
                    </div>
                </div>

                <div onclick="searchByLikeNum()" class="gonglve-nav m-t-20" data-cs-t="按热度搜索">
                    <div class="nav-item" data-cs-p="按热度搜索">
                        <div class="nav-title"><h3>按热度搜索</h3></div>
                        <input type="hidden" id="sortByLike" name="sortByLike"/>
                    </div>
                </div>

                <div onclick="searchByCommentsNum()" class="gonglve-nav m-t-20" data-cs-t="攻略导航">
                    <div class="nav-item" data-cs-p="海外冬季目的地精选">
                        <div class="nav-title"><h3>按评论数搜索</h3></div>
                        <input type="hidden" id="sortByComment" name="sortByComment"/>
                    </div>
                </div>
            </form>

            <div class="app_d m-t-40">
                <h3><a href="javascript:void(0)"><img src="<%=path%>/css/images/metro.png" alt=""
                                                      width="50" height="50"></a></h3>
                <div class="domn_in">
                    <h4><a href="javascript:void(0)">武汉Metro地铁APP下载
                        <div style="margin-left: 25px"><img src="<%=path%>/css/images/metro.png"
                                                            style="position: absolute; z-index: 99; width: 130px; display: none;">
                        </div>
                    </a></h4>
                    <p>
                        <a style="cursor: auto;">iPhone版</a>
                        <span>|</span>
                        <a style="cursor: auto;">Android版</a>
                    </p>
                    <div class="clear"></div>
                </div>
                <div class="clear"></div>
            </div>
        </div>

        <!--滑动图片-->
        <div id="slide" class="slide">
            <ul id="slide_box" style="left: 0px;">
                <li><a href="javascript:void(0)" ><img
                        src="/images/wKgBEFtrlBWAUHczAAR1Jh3BMT410.jpg"></a></li>
                <li><a href="javascript:void(0)" target="_blank"><img
                        src="/images/wKgED1ujcYOAajw-AAmb2Ru77hU284.png"></a></li>
                <li><a href="javascript:void(0)"><img
                        src="/images/wKgBEFrikRaAZO1cAAR67VzFWpU34.jpg"></a></li>
                <li><a href="javascript:void(0)"><img
                        src="/images/wKgBEFsYhsCAUh5KAAXn20e3Ig4130.png"></a></li>
                <li><a href="javascript:void(0)"><img
                        src="/images/wKgBEFsPa9CAadCJAAEo1LsX27I73.jpg"></a></li>
            </ul>
            <ol id="thumb_box">
                <li data-id="0" class="active">1</li>
                <li data-id="1" class="">2</li>
                <li data-id="2" class="">3</li>
                <li data-id="3" class="">4</li>
                <li data-id="4" class="">5</li>
            </ol>
        </div>
    </div>


    <div class="gonglve_wrap clearfix">
        <div class="cont-main _j_feed_list">
            <div class="hd clearfix">
                <h3>推荐攻略</h3>
            </div>
            <div class="gl-post">
                <div data-cs-t="gonglve_feed" class="_j_feed_data"
                     data-feed="[{&quot;fid&quot;:&quot;25449&quot;,&quot;type&quot;:&quot;3&quot;},{&quot;fid&quot;:&quot;124122&quot;,&quot;type&quot;:&quot;1&quot;},{&quot;fid&quot;:&quot;158226&quot;,&quot;type&quot;:&quot;1&quot;},{&quot;fid&quot;:&quot;69638&quot;,&quot;type&quot;:&quot;3&quot;},{&quot;fid&quot;:&quot;280709&quot;,&quot;type&quot;:&quot;1&quot;},{&quot;fid&quot;:&quot;291237&quot;,&quot;type&quot;:&quot;3&quot;},{&quot;fid&quot;:&quot;82402&quot;,&quot;type&quot;:&quot;3&quot;},{&quot;fid&quot;:&quot;104314&quot;,&quot;type&quot;:&quot;1&quot;},{&quot;fid&quot;:&quot;152930&quot;,&quot;type&quot;:&quot;3&quot;},{&quot;fid&quot;:&quot;282865&quot;,&quot;type&quot;:&quot;1&quot;}]">

                    <c:forEach var="sk" items="${sceneList}">
                        <div class="feed-item _j_feed_item" data-fid="124122" data-type="1" data-cs-p="位置_2">
                            <a href="/${sk.id}/detail" target="_blank">
                                <div class="title">
                                        ${sk.name}
                                    <div onclick="likeClick('${sk.id}')" class="rev-item" style="float: right">
                                        <a id="like_tag_${sk.id}" class="useful ${empty sk.currUserLike ? '' : 'on'}" data-id="191766807" title="点赞">
                                            <i></i><span id="like_num_${sk.id}" class="useful-num">${empty sk.likeNum ? '0' : sk.likeNum}</span>
                                        </a>
                                    </div>
                                </div>
                                <dl class="art clearfix">
                                    <dt>
                                        <img src="/images/${fn:split(sk.imageUrls,',')[0]}.jpg" style="width: 220px;">
                                    </dt>
                                    <dd>
                                        <div class="info">
                                                ${fn:substring(sk.summary,0,100)}...
                                        </div>
                                        <div class="ext-r"><span class="nums">${empty sk.commentNum ? '0' : sk.commentNum}条评论</span></div>
                                    </dd>
                                </dl>
                            </a>
                        </div>
                    </c:forEach>
                </div>
            </div>
        </div>

        <div class="clear"></div>
    </div>
</div>
<script src="<%=path%>/js/jquery-1.11.2.min.js"></script>
<script src="<%=path%>/js/slider.js"></script>
<script language="javascript" type="text/javascript">
    $(function () {
        // 首页轮滑图
        var bannerSlider = new Slider($('#slide'), {
            time: 5000,
            delay: 400,
            event: 'hover',
            auto: true,
            mode: 'fade',
            controller: $('#thumb_box'),
            activeControllerCls: 'active'
        });
        $('#slide .flex-prev').click(function () {
            bannerSlider.prev()
        });
        $('#slide .flex-next').click(function () {
            bannerSlider.next()
        });

    });

    // 输入框搜索
    function inputSearch() {
        $("#search_form").submit();
    }

    // 点赞数搜索
    function searchByLikeNum() {
        $("#sortByLike").val("1");
        $("#search_form").submit();
    }

    // 按评论数搜索
    function searchByCommentsNum() {
        $("#sortByComment").val("1");
        $("#search_form").submit();
    }

    // 点赞或取消点赞.sceneId:景点id
    function likeClick(sceneId) {
        $.post(
            "/praise",
            {sceneId:sceneId},
            function (data) {
                if (data.result == null){
                    window.location.href = '/page_login';
                    return false;
                }

                if (data.result == '0'){
                    layer_alert(data.message);
                    return false;
                }
                $("#like_num_"+sceneId).html(data.like_num);
                if (data.type == '0'){      // 取消点赞
                    $("#like_tag_"+sceneId).removeClass('on');
                }else{
                    $("#like_tag_"+sceneId).addClass('on');
                }
            }
        )
    }
</script>


<link href="<%=path%>/css/mfw-footer.css" rel="stylesheet" type="text/css">

<div id="footer">

</div>


</body>
</html>