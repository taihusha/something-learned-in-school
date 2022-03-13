
const app = getApp()

Page({
  //从服务器端获取
  data:{
    testPaper : [],
    userInfo: {},
    hasUserInfo: false,
    canIUse: wx.canIUse('button.open-type.getUserInfo')
  },
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
    wx.request({
      url: app.globalData.domain+'/page',
      data: {
        openid:wx.getStorageSync('openid')
      },
      method: 'GET', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
      // header: {}, // 设置请求的 header
      success: function(res){
        // success
        that.setData({
          testPaper:res.data
        })
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
  onExpland: function(event){
      //收缩展开试卷列表
      let index = event.currentTarget.dataset.index;
      let testPaper = this.data.testPaper;
      testPaper[index].isOpen = !testPaper[index].isOpen;
      this.setData({
        testPaper : testPaper
      })
  },
  onShowPaper: function(e) {
    let year=e.currentTarget.dataset.year
    let num=e.currentTarget.dataset.num
    if (year=='2012年国家司法考试' && num==4) {
      return 
    }
    wx.request({
      url: app.globalData.domain+'/page/'+year+'/'+num,
      data: {
        openid:wx.getStorageSync('openid')
      },
      method: 'GET', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
      // header: {}, // 设置请求的 header
      success: function(res){
        // success
        wx.setStorage({
          key: 'problems',
          data: res.data,        
        })
        wx.navigateTo({
          url: '/pages/problem/problem?origin='+year+'_'+num,
        })
      },
    })
  }
})