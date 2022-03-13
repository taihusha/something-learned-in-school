// packageA/pages/wrong_pro/wrong_pro.js
const app = getApp()
Page({

  /**
   * 页面的初始数据
   */
  data: {
    //从服务端获取
    userInfo: {},
    hasUserInfo: false,
    canIUse: wx.canIUse('button.open-type.getUserInfo'),
    modalShow: false,//是否显示弹窗
    wrongProblem : {}, //弹窗的问题
    wrong_pro : [], //当前错题列表
    wrong_all: [], //所有错题列表
    times: ["-按日期条件筛选"], //可选时间列表
    origins: ["-按来源条件筛选"], //可选来源
    origin_index:0, //来源的序号
    time_index:0//时间的序号
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function () {
    var that=this
    if (app.globalData.userInfo) {
      this.setData({
        userInfo: app.globalData.userInfo,
        hasUserInfo: true
      })
    } else if (this.data.canIUse) {
      app.userInfoReadyCallback = res => {
        this.setData({
          userInfo: res.userInfo,
          hasUserInfo: true
        })
      }
    } else {
      wx.getUserInfo({
        success: res => {
          app.globalData.userInfo = res.userInfo
          this.setData({
            userInfo: res.userInfo,
            hasUserInfo: true
          })
        }
      })
    }
    wx.showLoading({
      title: '加载中',
    })
    var openid=wx.getStorageSync('openid')
    wx.request({
      url: app.globalData.domain+'/user/getCollecion',
      data: {
        openid:openid,
      },
      method: 'GET', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
      // header: {}, // 设置请求的 header
      success: function(res){
        // success
        console.log(1)
        that.setData({
          wrong_pro:res.data,
          wrong_all : res.data
        })
         //设置限制框的时间范围
         if(that.data.wrong_pro!=null){
         for(let i=0 ; i<that.data.wrong_pro.length; i++){
           if(that.data.times.indexOf(that.data.wrong_pro[i].time.substring(0,11))==-1){
               that.data.times.push(that.data.wrong_pro[i].time.substring(0,11))
           }
           if(that.data.origins.indexOf(that.data.wrong_pro[i].origin)==-1){
               that.data.origins.push(that.data.wrong_pro[i].origin)
           }
         }
         that.setData({
            times: that.data.times.sort(),
            origins: that.data.origins.sort()
         })
        }
         //
         wx.hideLoading()
      },
    })
  },
  getUserInfo: function (e) {
    app.globalData.userInfo = e.detail.userInfo
    this.setData({
      userInfo: e.detail.userInfo,
      hasUserInfo: true
    })
  },
  //打开题目弹窗
  showProblem: function(e){
    this.setData({
      modalShow: true,
      wrongProblem: e.currentTarget.dataset.problem
    })
  },
  //修改题目isWrong
  onMyEvent: function(e){
   var list = this.data.wrong_all //修改总的错题列表
   for(let i =0 , len = list.length; i<len;++i){
     if(list[i].Id == e.detail.index){
       list[i].isWrong = true
     }
   }
   this.setData({
      wrong_all:list
   })
   this.changeWrongPro(this.data.origin_index,this.data.time_index)
  },
  //日期限制框change
  bindDateChange: function(e){
    this.changeWrongPro(this.data.origin_index, e.detail.value)
  },
  //时间限制框change
  bindOriginChange: function(e){
    this.changeWrongPro( e.detail.value, this.data.time_index)
  },
  //改变页面显示的题目列表
  changeWrongPro:function(originindex, timeindex){
    var tmpwrong = new Array()
    if(this.data.wrong_all != null){
    for(let i = 0 ; i<this.data.wrong_all.length; i++){
      if((this.data.wrong_all[i].origin.match(this.data.origins[originindex]) != null||originindex==0)&&(this.data.wrong_all[i].time.match(this.data.times[timeindex]) != null||timeindex==0)){
        tmpwrong.push(this.data.wrong_all[i])
      }
    }
    this.setData({
      origin_index: originindex,
      time_index: timeindex,
      wrong_pro: tmpwrong
    })
  }
  },
  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {
    let list=this.data.wrong_all
    let remove=new Array()
    if(list==null)
      return
    for (let i=0;i<list.length;i++) {
      if (list[i].isWrong) {
        remove.push(list[i].problemId)
      }
    }
    wx.request({
      url: app.globalData.domain+'/practice/deletecollection',
      data: {
        openid:wx.getStorageSync('openid'),
        problemid:remove
      },
      method: 'POST', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
      header:{
        'content-type':'application/x-www-form-urlencoded',
      },
    })
  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})