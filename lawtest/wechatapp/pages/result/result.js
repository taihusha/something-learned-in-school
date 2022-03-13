// pages/results/results.js
var app = getApp();
const imageList = [['http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEKuZIEK.yH75Z1sJsTq7sLkh2P0vGEFk4nB1JOXCGnDfQKqofydjmLQVno21FaF.cAyoKdcTCbO9vAoC4PWtrm0!/r',
'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEGush68wd3cpTdqHFvSsMjn29QM3FYcLDPqR.vtEDtu5fKcupBaecxTiTsg69Vl6ef7a6tORuC3*4TgxcYOAlTw!/r',
'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEJPPEYdt7ficy9*fxbszy6t1JT*uS5Lt7woEuS*DtMHWel3cMxf6ydVSShvrqNXGl7a7hC8Sf3v8QLW85PaNaDI!/r',
'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEOj5qaaSk4ltjHbRlhOV*OI8b.C6xpCs1e1eyOIPGIkcE85vN6jq4duqo*27ZNufSEdFu1NfXsUTUZms60q9Cak!/r',
'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrENLuG5rNxWPC0Nazz7VWev3r4Yapnl5vh*omRJIo1KaHqarsP5YtVsIAR56iN7vYgwoJCJqNxZIoiDeO.ULnEe8!/r',
'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrENX*jSU8Z2HsN3KYpBGZ6Kg.FPMaXGCvAPfca8p63b5Cc99G8flw94IKuyEaHr9OJEt8yiWEBPguC67Cbj5QCFE!/r'],
[
  'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEAn4Pc7A6XP8qaqIf3ej2bWKKV4b*NR4SkBBjxYPELt2Ev.GMP90KZVIGpaoE3g4.eAsfRpAVdjf93q.R3D4KV4!/r',
  'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEGFDfYrxrKCtNfxGOZD15g3uuoYLvzSaQE81yIaNPvLDJb3NIuNUWzgDuUOmpurUXnz7Xae1nhM7kyq7nrJt8gQ!/r',
  'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEC0FSGnzV4xNfKd5sCugUkhnubMiMCtkhrw7d41a188.I7HTqKYxmMEe8r88okJvecAW3Kj0OX8cWDdOOHw*PDo!/r',
  'http://photogz.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEMi4Kgrx3yaPboOFwiY4WeYu0y2ENC4WQ2jqWln9KqUgcqWGLtGeStEh5fPIYHDqnjH6tZ4.4auZD2AvkyBZT18!/b',
  'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEOqa*tqk3sg314mV7FxXD0vhy2AeXvjywp7exFfBF3bI9D14wZ3y9vIvREPSxrSGd5U.34.04HrIGIc6oTw7hho!/r',
  'http://r.photo.store.qq.com/psc?/V12WS7Lx4PFv5A/TmEUgtj9EK6.7V8ajmQrEFQUM*4jYJPF01zh8HNYz5AunAOIO5CGZQmH304B1aVbiIwCjIqWXIvWVq.jbBsYYt0qz2D604xkp0RicdomLho!/r'
]]

Page({
  data: {
    origin:'',
    totalScore: null, // 分数
    wrongList: [], // 错误的题数
    wrongProblem: {},
    isWenda:false,
    remark: ["人間讃歌は「勇気」の讃歌ッ！！人間のすばらしさは勇気のすばらしさ！！", "貧弱貧弱！！", "我一个滑铲，从他身下滑过。", "我从短暂的人生当中学到一件事，越是玩弄计谋，就越会发现人类的能力是有极限的。"], // 评语
    timer: '',
    opacity: 7.0,
    image: imageList[0][Math.floor(Math.random() * 6)],
    imageBack: imageList[1][Math.floor(Math.random() * 6)],
  },
  onLoad: function (options) {
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
    wx.getStorage({
      key: 'wrongList',
      success: function(res){
        that.setData({
          wrongList:res.data
        })
      }
    })
    this.setData({
      totalScore: options.totalScore,
      origin:options.origin
    })
    if (options.origin.endsWith('4')) {
      this.setData({
        isWenda:true
      })
    }

  },
  onHide: function () {
    this.setData({
      opacity: 7.0,
    })
    clearInterval(this.data.timer);
  },
  // 查看错题
  toView: function(e){
    // 显示弹窗
    this.setData({
      modalShow: true,
      wrongProblem : this.data.wrongList[e.currentTarget.dataset.option],
      isWenda:this.data.isWenda
    })
  },
  // 返回首页
  toIndex: function () {
     wx.redirectTo({
       url: '/pages/mainUI/main',
     })
  },
  again: function(e) {
    console.log(e)
    let origin=this.data.origin
    if (origin=='section') {
      wx.redirectTo({
        url: '/pages/section/section',
      })
    } else if (origin=='tiku') {
      wx.request({
        data:{
          openid:wx.getStorageSync('openid')
        },
        url: app.globalData.domain+'/practice',
        method: 'GET', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
        // header: {}, // 设置请求的 header
        success: function(res){
          wx.setStorage({
            key: 'problems',
            data: res.data,        
          })
        },
      })
      wx.redirectTo({
        url: '../problem/problem?origin=tiku',
      })
    } else {
      wx.redirectTo({
        url: '/pages/testpaper/testpaper',
      })
    }
  },
  wrong: function() {
    wx.navigateTo({
      url: '/pages/wrongpro/wrongpro',
    })
  },
  playbg: function () {
    let that = this;
    var count = 0;
    var opflag = false;
    var opdir = true;
    var opacity = 3.5;
    that.data.timer = setInterval(function () {
        count++;
        if (count % 200 == 0 && count != 0) {
          opflag = true;
          opdir = !opdir;
        }
        if (opflag == true && opdir == false) {
          opacity -= 0.05;
          if (opacity == -3.5) {
            opflag = false;
          }
          that.setData({
            opacity: opacity + 1.5
          })
        }
        if (opflag == true && opdir == true) {
          opacity += 0.05;
          if (opacity == 3.5) {
            opflag = false;
          }
          that.setData({
            opacity: opacity + 1.5
          })
        }
        if (Math.floor(opacity) == -5) {
          that.setData({
            image: imageList[0][Math.floor(Math.random() * 6)]
          })
        }
        if (Math.floor(opacity) == 3) {
          that.setData({
            imageBack: imageList[1][Math.floor(Math.random() * 6)]
          })
        }
      }, 50)
  },
  onShow: function () {
    this.playbg();
    var problems=new Array()
    let wrong=wx.getStorageSync('wrongList')
    if(this.data.isWenda)
       return
    for (let i=0;i<wrong.length;i++) {
      problems.push(wrong[i].problemId)
    }

    wx.request({
      url: app.globalData.domain+'/practice/addwrong',
      data: {
        openid:wx.getStorageSync('openid'),
        problems:problems
      },
      header:{
        'content-type':'application/x-www-form-urlencoded',
      },
      method: 'POST', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
      success: function(res){
        console.log(1)
      },
    })
  }
})