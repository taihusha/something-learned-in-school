
const app = getApp()

Page({
  //从服务器端获取
  data:{
    knowLedgePoints : [],
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
      url: app.globalData.domain+'/Klp',
      data: {},
      method: 'GET', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
      // header: {}, // 设置请求的 header
      success: function(res){
        that.setData({
          knowLedgePoints:that.setDone(res.data)
        })
        wx.hideLoading()
      }
    })
  },
  setDone: function(points) {
    for (let i=0;i<points.length;i++) {
      for (let j=1;j<=3;j++) {
        let key=points[i].content+'_'+j
        let value=wx.getStorageSync(key)
        if (value=='') {
          points[i].done[j-1] = 0
          continue
        } else {
          for (let k=0;k<value.length;k++) {
            if (value[k].isAnswer==1) {
              points[i].done[j-1]++
            }
          }
        }
      }
    }

    return points
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
      let knowLedgePoints = this.data.knowLedgePoints;
      knowLedgePoints[index].isOpen = !knowLedgePoints[index].isOpen;
      this.setData({
        knowLedgePoints : knowLedgePoints
      })
  },
  onShowPaper: function(e){
    var that=this
    let key=e.currentTarget.dataset.content+'_'+e.currentTarget.dataset.num
    let value=wx.getStorageSync(key)
    let item=['10', '20']
    wx.showActionSheet({
      itemList: item,
      success (res) {
        let num=item[res.tapIndex]
        if (value=='') {
          wx.request({
            url: app.globalData.domain+'/Klp/'+e.currentTarget.dataset.content+'/'+e.currentTarget.dataset.num,
            data: {},
            method: 'GET', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
            // header: {}, // 设置请求的 header
            success: function(res){
              // success
              wx.setStorage({
                key: 'problems',
                data:  that.pickProblem(res.data,num),        
              })
              wx.setStorage({
                key: key,
                data: res.data,
              })
              wx.navigateTo({
                url: '/pages/problem/problem?origin=section&key='+key,
              })
            },
          })
        }else {
          if(value[0].isAnswer == 1){
            wx.showModal({
              title: '提示',
              content: '你已经全部做完，是否清空做题记录',
              success: function(res) {
                if (res.confirm) {
                  wx.removeStorageSync(key)
                  that.setData({
                    knowLedgePoints:that.setDone(that.data.knowLedgePoints)
                  })
                  return
                } else if (res.cancel) {
                  return
                }
              }
            })
          } else {
            wx.setStorage({
              key: 'problems',
              data: that.pickProblem(value,num),        
            })
            wx.navigateTo({
              url: '/pages/problem/problem?origin=section&key='+key,
            })
          }

        }   
      },
    })
  },
  contains: function(list,object) {
    for (let i=0;i<list.length;i++) {
      if (list[i]===object) {
        return true
      }
    }
    return false
  },
  pickProblem: function(list,numstring) {
    let newList=new Array()
    let num=parseInt(numstring)
    for (let i=0;i<num&&i<list.length;i++) {
      if (list[i].isAnswer==1) {
        break
      }
      newList.push(list[i])
    }
    return newList
  },
})