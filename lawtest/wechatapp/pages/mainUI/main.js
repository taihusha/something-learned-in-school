
const app = getApp()
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
    userInfo: {},
    hasUserInfo: false,
    canIUse: wx.canIUse('button.open-type.getUserInfo'),
    timer: '',
    opacity: 7.0,
    image: imageList[0][Math.floor(Math.random() * 6)],
    imageBack: imageList[1][Math.floor(Math.random() * 6)],
    motto: ['「ホワイトアルバムの季節」が、また、やってきた。', '無限大な夢のあとの、何もない世の中じゃ。', '翼がないから、人は飛び方を探すのだ。'],
    mottoIndex: Math.floor(Math.random() * 3),
  },
  onLoad: function () {
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
  },
  onShow: function () {
    this.playbg();
    this.setData({
      mottoIndex: Math.floor(Math.random() * 3),
    })
  },
  onHide: function () {
    this.setData({
      opacity: 7.0,
    })
    clearInterval(this.data.timer);
  },
  getUserInfo: function (e) {
    var that=this
    console.log(e.detail.errMsg)
    if (e.detail.errMsg=='getUserInfo:ok') {
      wx.login({
        success:function(res){
          // 发送 res.code 到后台换取 openId, sessionKey, unionId
          if (res.code) {
            wx.request({
              url: app.globalData.domain+'/login',
              data: {
                code:res.code
              },
              method: 'GET', 
              success: function(res){
                // success
                that.setData({
                  hasUserInfo:true,
                  userInfo:e.detail.userInfo
                })
                wx.setStorage({
                  key: 'openid',
                  data: res.data.openid,
                })
              },
            })
          } else {
            console.log('登录失败'+res.errMsg)
          }
        }
      }) 
    }
  },
  checkLogin:function() {
    var value=wx.getStorageSync('openid')
    if (value==''||!this.data.hasUserInfo) {
      wx.showModal({
        title: '提示',
        content: '请登录',
        showCancel:false
      })
    } else {
      return true
    }
  },
  zhangjie: function(e) {
    if (this.checkLogin()) {
      wx.navigateTo({
        url: '../section/section',
      })
    }
  },
  zhenti: function (e) {
    if (this.checkLogin()) {
      wx.navigateTo({
        url: '../testpaper/testpaper',
      })
    }
  },
  tiku: function (e) { 
    if (this.checkLogin()) {
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
            success: function() {
              wx.navigateTo({
                url: '../problem/problem?origin=tiku',
              })     
            }        
          })
        },
      })
    }
  },
  shouchang: function() {
    wx.navigateTo({
      url: '/pages/difficult/difficult',
    })
  },
  cuoti: function() {
    if (this.checkLogin()) {
      wx.navigateTo({
        url: '/pages/wrongpro/wrongpro',
      })
    }
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
})
