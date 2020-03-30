<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>
<%@ page isELIgnored="false" %>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + path + "/";
%>
<html style="">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <link rel="stylesheet" type="text/css" href="<%=path%>/css/style1536672475627.css">
    <link rel="stylesheet" type="text/css" href="<%=path%>/css/style1536672475627(1).css">
    <link rel="stylesheet" type="text/css" href="<%=path%>/css/style1536672475627(2).css">
    <link rel="stylesheet" type="text/css" href="<%=path%>/css/style1536672475627(3).css">
    <title>${sceneInfo.name}</title>

    <link href="<%=path%>/css/detail_base.css" rel="stylesheet" type="text/css">

    <link href="<%=path%>/css/detail_mdd.css" rel="stylesheet" type="text/css">
    <link href="<%=path%>/css/guide.css" rel="stylesheet" type="text/css">

    <%@include file="/WEB-INF/common/head.jsp"%>
    <script language="javascript" src="<%=path%>/js/js_stylie_2.js" type="text/javascript" crossorigin="anonymous"></script>
    <script language="javascript" src="<%=path%>/js/jquery.upnum.js" type="text/javascript" crossorigin="anonymous"></script>

    <script async="" src="<%=path%>/js/js_stylie_1.js" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="<%=path%>/css/map-mark.v2.css">
    <script async="" src="<%=path%>/js/BrowserState.js" crossorigin="anonymous"></script>

    <script src="http://api.map.baidu.com/api?v=2.0&ak=53oVIOgmSIejwV7EfphPgTynOZbIiVYu"></script>
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

<div class="container" data-cs-t="景点详情页">
    <script language="javascript" src="<%=path%>/js/index.js" type="text/javascript" crossorigin="anonymous"></script>

    <style type="text/css">
        .share span {
            display: none;
        }
        .share a {
            display: block;
            border-radius: 5px;
            margin: 5px 0;
            width: 30px;
            height: 30px;
            overflow: hidden;
        }
        .m-t-10 {
            margin-top: 10px;
        }
    </style>
    <script type="text/javascript">
        $("#_j_sharecnt").attr('data-content', '昙华林，咖啡馆、创意馆、汉绣馆穿插在50多处百年以上的近代历史建筑中');

        function commentScene() {
            document.getElementsByTagName('BODY')[0].scrollTop=document.getElementsByTagName('BODY')[0].scrollHeight;
        }
    </script>
    <!-- 分享 E-->
    <div class="row row-top">
        <div class="wrapper">

            <!-- POI名称 S-->
            <div class="title">
                <h1>${info.name}</h1>
            </div>

            <div style="height: 60px;">
                <div class="r-nav" id="poi-navbar" data-cs-p="快捷导航">
                    <ul class="clearfix">
                        <li data-scroll="overview" class="on">
                            <a title="概况">概况</a>
                        </li>
                        <li data-scroll="attractions" style="display: none">
                            <a title="景点亮点">景点亮点</a>
                        </li>
                        <li data-scroll="commentlist" class="">
                            <a title="huster点评">huster点评<span class="comment_num">（${comments.size()}条）</span></a>
                        </li>
                        <li class="nav-right m-t-10">
                            <a class="btn-reviews" title="我要点评"  href="javascript:void(0)" onclick="commentScene()">我要点评</a>
                        </li>
                    </ul>
                </div>
            </div>
            <!-- 快捷导航 E-->
        </div>
    </div>
    <script type="text/javascript">
        (function () {
            //面包屑
            $('.drop').hover(function () {
                var target = $(this);
                clearTimeout(target.data('hideTimer'));
                target.addClass('open');
                target.children('bd').fadeIn(200);
            }, function () {
                var target = $(this);
                target.data("hideTimer", setTimeout(function () {
                    target.removeClass('open');
                    target.children('bd').fadeOut(200);
                }, 100));
            });
            //导航
            var $navbar = $('#poi-navbar'),
                offset_top,
                $lis = $navbar.find("li").not('.nav-right');
            $('<div/>').insertBefore($navbar).append($navbar).height($navbar.outerHeight(true));
            $(function () {
                offset_top = $navbar.offset().top;
                $(window).bind('scroll.poinav', setFixed).trigger("scroll.poinav");
            });
            $(document).delegate("[data-scroll]", "click", function () {
                scrollTo($(this));
            });

            function setFixed() {
                var $rows = $('body >.container >[data-anchor]'),
                    scrolltop = $(document).scrollTop(),
                    h,
                    _lis = $lis.filter(":visible"),
                    currIndex;
                if (scrolltop > offset_top) {
                    if (!$navbar.hasClass('fixed')) {
                        $navbar.addClass('fixed');
                    }
                    h = $navbar.outerHeight(true);
                    for (var $li, $row, top, i = 0, j = _lis.length; i < j; i++) {
                        $row = $rows.filter("[data-anchor=" + ($li = _lis.eq(i)).attr("data-scroll") + "]");
                        if ($row[0] && (top = $row.offset().top) && ( /*i == (j - 1) ||*/
                            ((top - h <= scrolltop) && (top + $row.outerHeight() - h > scrolltop)))) {
                            currIndex = i;
                            break;
                        }
                    }
                    if (i == j) {
                        _lis.removeClass("on");
                    } else {
                        _lis.eq(currIndex || 0).addClass("on").siblings().removeClass("on");
                    }
                } else {
                    if ($navbar.hasClass('fixed')) {
                        $navbar.removeClass('fixed');
                    }
                    _lis.eq(0).addClass("on").siblings().removeClass("on");
                }
            }

            function scrollTo(target, pos) {
                pos = target ? target.data('scroll') : pos;
                var $target = $('[data-anchor=' + pos + ']'), top;
                if ($target[0]) {
                    top = $target.offset().top;
                    if (top > offset_top) {
                        top -= $navbar.outerHeight();
                    }
                    $('html,body').animate({
                        scrollTop: Math.ceil(top)
                    }, 500);
                }
            }

        })();
    </script>
    <div data-anchor="overview">
        <div class="row row-picture row-bg">
            <div class="wrapper">
                <a class="photo" data-cs-p="相册" href="javascript:void(0)">
                    <div class="bd">
                        <div class="pic-big"><img src="/images/${fn:split(sceneInfo.imageUrls,',')[0]}.jpg" width="690"
                                                  height="370"></div>
                        <div class="pic-small"><img src="/images/${fn:split(sceneInfo.imageUrls,',')[1]}.jpg" width="305"
                                                    height="183"></div>
                        <div class="pic-small"><img src="/images/${fn:split(sceneInfo.imageUrls,',')[2]}.jpg" width="305"
                                                    height="183"></div>
                    </div>
                </a></div>
        </div>

        <!-- 简介 S -->
        <div class="mod mod-detail" data-cs-p="概况">
            <div class="summary">
                ${sceneInfo.summary}
            </div>

            <ul class="baseinfo clearfix">
                <li class="item-time">
                    <div class="label">用时参考</div>
                    <div class="content">${sceneInfo.time}</div>
                </li>
            </ul>

            <dl>
                <dt>交通</dt>
                <dd>${sceneInfo.traffic}</dd>
            </dl>
            <dl>
                <dt>门票</dt>
                <dd>
                    <div>${sceneInfo.ticket}<br>
                    </div>

                </dd>
            </dl>
            <dl>
                <dt>开放时间</dt>
                <dd>${sceneInfo.openTime}<br>
                </dd>
            </dl>
        </div>
        <!-- 简介 E -->

        <!-- 位置 S -->
        <div class="mod mod-location">
            <div class="mhd" style="overflow: hidden;">景点位置<p class="sub">${sceneInfo.location}</p></div>

            <div id="container" style="
            height: 270px;
            width:1000px;
            overflow:hidden;">
            </div>
        </div>

    </div>

    <%--centerAndZoom方法中的第一个参数动态传入景点地址--%>
    <script type="text/javascript">
        var map = new BMap.Map("container");
        map.centerAndZoom("${sceneInfo.location}", 18);
        map.enableScrollWheelZoom(); //启用滚轮放大缩小，默认禁用
        map.enableContinuousZoom(); //启用地图惯性拖拽，默认禁用

        map.addControl(new BMap.NavigationControl()); //添加默认缩放平移控件
        map.addControl(new BMap.OverviewMapControl()); //添加默认缩略地图控件
        map.addControl(new BMap.OverviewMapControl({
            isOpen: true,
            anchor: BMAP_ANCHOR_BOTTOM_RIGHT
        })); //右下角，打开

        var localSearch = new BMap.LocalSearch(map);
        localSearch.enableAutoViewport(); //允许自动调节窗体大小

        map.clearOverlays(); //清空原来的标注
        var keyword = document.getElementById("text_").value;
        localSearch.setSearchCompleteCallback(function(searchResult) {
            var poi = searchResult.getPoi(0);
            document.getElementById("result_").value = poi.point.lng + "," + poi.point.lat;
            map.centerAndZoom(poi.point, 13);
            var marker = new BMap.Marker(new BMap.Point(poi.point.lng, poi.point.lat)); // 创建标注，为要查询的地方对应的经纬度
            map.addOverlay(marker);
            var content = document.getElementById("text_").value + "<br/><br/>经度：" + poi.point.lng + "<br/>纬度：" + poi.point.lat;
            var infoWindow = new BMap.InfoWindow("<p style='font-size:14px;'>" + content + "</p>");
            marker.addEventListener("click", function() {
                this.openInfoWindow(infoWindow);
            });
            // marker.setAnimation(BMAP_ANIMATION_BOUNCE); //跳动的动画
        });
        localSearch.search(keyword);
    </script>

    <!-- 评论列表 S -->
    <div data-anchor="commentlist" id="commentlist">
        <div id="pagelet-block-542642a7882b8040114430407771d70d" class="pagelet-block"
             data-api=":poi:pagelet:poiCommentListApi" data-params="{&quot;poi_id&quot;:&quot;6163&quot;}"
             data-async="1" data-controller="/js/poi/ControllerPoiComment">
            <div class="mod mod-reviews" data-cs-p="评论列表">
                <div class="mhd mhd-large">huster点评<span>（共有<em id="comment_num_id" class="comment_num">${comments.size()}</em>条真实评价）</span></div>
                <div class="_j_commentlist">
                    <div class="rev-list">
                        <ul id="comment_ul">
                            <c:forEach var="c" items="${comments}">
                                <li class="rev-item comment-item clearfix">
                                        <div class="user"><a class="avatar" href="javascript:void(0)"><img
                                                src="/images/user.png" width="48" height="48"></a></div>
                                        <span class="name">${c.username}   评论时间：${c.createTime}</span>
                                        <span class="s-star s-star1"></span>
                                        <p class="rev-txt">${c.content}</p>
                                </li>
                            </c:forEach>
                        </ul>
                    </div>
                    <div class="clearfix com-form m-t-10">
                        <div class="img"><img src="https://n3-q.mafengwo.net/s12/M00/35/6C/wKgED1uqIpCARLIhAAAZUeRPlFM676.png?imageMogr2%2Fthumbnail%2F%2148x48r%2Fgravity%2FCenter%2Fcrop%2F%2148x48%2Fquality%2F100 "></div>
                        <div class="fm-tare user-log">
                            <textarea id="commentContent" class="_j_comment_content">说点什么吧...</textarea>
                            <button type="button" class="gotoLogin" data-gtype="2" onclick="commentClick()">评论</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
<script>
    function commentClick() {
        var content = $("#commentContent").val();
        if (content == ''){
            layer_alert("评论不能为空！");
            return false;
        }

        var commentTime = getFormatTime(new Date(),"yyyy-MM-dd hh:mm:ss");
        $.post(
            "/comment",
            {userId:'${sessionScope.userId}',sceneId:'${sceneInfo.id}',content:content,createTime:commentTime},
            function (data) {
                if (data.result == null){
                    window.location.href = '/page_login';
                    return false;
                }

                if (data.result == '0'){
                    layer_alert(data.message);
                    return false;
                }

                layer.msg("评论成功");
                var pre_comment_num = parseInt($("#comment_num_id").html());
                $(".comment_num").html(pre_comment_num+1);
                var tag = '<li class="rev-item comment-item clearfix">' +
                    '                                ' +
                    '                                    <div class="user"><a class="avatar" href="javascript:void(0)"><img src="/images/user.png" width="48" height="48"></a></div>' +
                    '                                    <span class="name">${sessionScope.username}   评论时间：'+commentTime+'</span>' +
                    '                                    <span class="s-star s-star1"></span>' +
                    '                                    <p class="rev-txt">'+content+'</p>' +
                    '                                ' +
                    '                            </li>';
                $("#comment_ul").append(tag);
            }
        )
    }
</script>
</body>
</html>