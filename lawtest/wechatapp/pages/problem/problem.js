// pages/python/python.js

//获取应用实例
const app = getApp()

//var questionData = new Array();
//判断值是否在数组中
function contains(a, obj) {
  var i = a.length;
  while (i--) {
    if (a[i] === obj) {
      return i;
    }
  }
  return -1;
}

Page({
  /**
   * 页面的初始数据
   */
  data: {
    userInfo: {},
    hasUserInfo: false,
    isLoading: true,
    swiper: {
      active: 0
    },
    isWenda:false,
    timer: '',//定时器名字
    countDownSecond: 0,//倒计时初始值
    countDownMin:1,
    layerlayer: {
      isLayerShow: false,//默认弹窗
      layerAnimation: {},//弹窗动画
    },
    key:'',
    origin:'',
    done: 0, // 选择的答案序列
    totalScore: 150, // 总分
    wrongList: [], // 错误的题目集合
    allList: [],//题号数据
    answers: {
      start: 0,//初始题号
      end: 0,//结束题号
      activeNum: 0,//当前显示条数
      onceLoadLength: 5,//一次向俩端加载条数，因我使用本地数据，此属性未实际使用
      isShowTip: false//默认是否显示提示
    },
  },

  //单选逻辑
  tapRadio: function (e) {
    let question = JSON.parse(e.detail.value)
    const items = question.options
    let index=question.Id
    let list=this.data.allList
    for (let i = 0, len = items.length; i < len; ++i) {
      items[i].checked = items[i].label === question.choose
    }
    question.isAnswer=1
    list.splice(index,1,question)
    this.setData({
      allList:list
    })
    if (this.data.answers.activeNum + 1 < this.data.allList.length) {
      setTimeout(() => this.onSwiper('left'), 200)
    } 
  },

  //多选逻辑
  tapCheckbox: function (e) {
    let thisOption = e.currentTarget.dataset.option
    let list=this.data.allList
    let index=thisOption[2]
    let question=this.data.allList[thisOption[2]]
    let optionlist = this.data.allList[thisOption[2]].options.map(function (option) {
      if(thisOption[0].label===option.label) {
        option.checked = !(option.checked)
      }
      return option
    })
    question.isAnswer=1
    question.options=optionlist
    list.splice(index,1,question)
    this.setData({
      allList:list
    })
  },
  setScoreGap: function(origin, list){
    var delta_r, delta_m
    if (origin=='tiku' || origin=='section') {
     delta_r = delta_m = 150/list.length
    } else {
      delta_r=1
      delta_m=2
    }
    return new Array(delta_r, delta_m)
  },
  getGrade:function () {
    let question=this.data.allList
    let origin=this.data.origin
    let wronglist=new Array()
    let score=150
    let delta= this.setScoreGap(origin, question)
    let delta_r = delta[0]
    let delta_m = delta[1]
    for (let i=0;i<question.length;i++) {
      let q=question[i]
      if (q.isAnswer==0) {
        score-= q.type=='单选'?delta_r:delta_m
        wronglist.push(q)
        continue
      }
      if (q.type=='单选' && q.choose!=q.a) {
          wronglist.push(q)
          score-=delta_r
      } else {
        let answer = ""
        q.options.map(function (option) {
          if (option.checked) {
            answer+=option.label
          }
        })
        q.choose=answer
        if (answer!=q.a) {
          wronglist.push(q)
          score-=delta_m
        }
      }
    }
    wx.setStorage({
      key: 'wrongList',
      data: wronglist,
    })
    this.setData({
      totalScore: parseInt(score)
    })
  },
  //提交确认逻辑
  tapConfirm: function(e) {
    var that=this
    let question=this.data.allList
    let problems=new Array()
    let origin=this.data.origin
    var completed =true 
    for (let i=0;i<question.length;i++) {
      problems.push(question[i].problemId)
      completed &= question[i].isAnswer === 1
    }
    var text='确认提交吗'
    if (!completed) {
      text='还有未完成的题目，'+text
    }
    this.getGrade()
    wx.showModal({
      title: '提示',
      content: text,
      success (res) {
        if (res.confirm) {
          wx.redirectTo({
            url: '/pages/result/result?totalScore='+that.data.totalScore+'&origin='+that.data.origin
          })
          wx.request({
            url: app.globalData.domain+'/addpracice',
            data: {
              openid:wx.getStorageSync('openid'),
              grade:that.data.totalScore,
              origin:origin
            },
            method: 'post', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
            header:{
              'content-type':'application/x-www-form-urlencoded',
            },
            success: function(res){
              console.log(2)
            },
          })
          
        } else if (res.cancel) {
          that.layerFooterClick()
        }
      }
    })
  },
  countDown: function () {
    let that = this;
    let countDownMin = that.data.countDownMin;
    let countDownSecond = that.data.countDownSecond;
      that.data.timer = setInterval(function () {
        if (countDownMin == 0 && countDownSecond ==0) {
          wx.showToast({
            title: '时间到了',
          })
          clearInterval(that.data.timer);
        }else{
          if (countDownSecond==0) {
            countDownMin--
            countDownSecond=59
          } else {
            countDownSecond--
          } 
        that.setData({
          countDownMin: countDownMin,
          countDownSecond:countDownSecond
        })}
      }, 1000)
  },
  //页码切换列表效果
  pageClick: function () {
    let layerAnimation = wx.createAnimation({
      transformOrigin: '50% 50%',
      duration: 500,
      timingFunction: 'ease',
      delay: 0
    })
    if (!this.data.layerlayer.isLayerShow) {
      layerAnimation.translate3d(0, 0, 0).step()
    } else {
      layerAnimation.translate3d(0, '100%', 0).step()
    }
    this.data.layerlayer.isLayerShow = !this.data.layerlayer.isLayerShow
    this.data.layerlayer.layerAnimation = layerAnimation
    this.setData(this.data)
  },
  //页码切换列表收缩
  layerFooterClick: function () {
    let layerAnimation = wx.createAnimation({
      transformOrigin: '50% 50%',
      duration: 500,
      timingFunction: 'ease',
      delay: 0
    })
    layerAnimation.translate3d(0, '100%', 0).step()
    this.data.layerlayer.isLayerShow = false
    this.data.layerlayer.layerAnimation = layerAnimation
    this.setData(this.data)
  },

  //收藏逻辑
  collectList: function () {
    let question=this.data.allList
    let index = this.data.answers.activeNum
    question[index].isStore=!question[index].isStore
    this.setData({
      allList:question
    })
  },

  setRecord: function() {
    let question=this.data.allList
    let collection=new Array()
    for (var i=0;i<question.length;i++) {
      if (question[i].isStore) {
        collection.push(question[i].problemId)
      }
    }
    if (collection.length==0) {
      return
    }
    wx.request({
      url: app.globalData.domain+'/practice/addcollection',
      data: {
        problems:collection,
        openid:wx.getStorageSync('openid')
      },
      header:{
        'content-type':'application/x-www-form-urlencoded',
      },
      method: 'POST', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT
    })
  },
  //题号变更逻辑
  setActiveNum: function (e) {
    let thisOption = e.currentTarget.dataset.option - 0
    this.data.answers.activeNum = thisOption
    this.data.isLoading = false
    this.layerFooterClick()
    this.getSubject()
  },
  
  //swiper切换
  setEvent: function (e) {
    this.data.swiper.touchstartEvent = e
    return false
  },
  //滑动结束
  touchEnd: function (e) {
    this.onSwiper(this.getDirection(this.data.swiper.touchstartEvent, e))
    return false
  },
  //swiper切换
  onSwiper: function (dire) {
    let that = this
    let active = 0
    let animationPre = wx.createAnimation({
      transformOrigin: '50% 50%',
      duration: 300,
      timingFunction: 'ease',
      delay: 0
    })
    let animationT = wx.createAnimation({
      transformOrigin: '50% 50%',
      duration: 300,
      timingFunction: 'ease',
      delay: 0
    })
    let animationNext = wx.createAnimation({
      transformOrigin: '50% 50%',
      duration: 300,
      timingFunction: 'ease',
      delay: 0
    })
    if (!this.$isLock) {//锁屏控制
      this.$isLock = true
      if (dire == 'bottom' || dire == 'top' || !dire) {
        this.$isLock = false
        return false
      }
      if (dire == 'right') {
        animationPre.translate3d('0', 0, 0).step()
        animationT.translate3d('100%', 0, 0).step()
        if (this.data.answers.activeNum > this.data.answers.start) {
          active = - 1
        } else {
          this.$isLock = false
          return
        }
      }
      if (dire == 'left') {
        animationT.translate3d('-100%', 0, 0).step()
        animationNext.translate3d('0', 0, 0).step()
        if (this.data.answers.activeNum < this.data.answers.end - 1) {
          active = 1
        } else {
          this.$isLock = false
          return
        }
      }
      this.data.swiper.animationPre = animationPre.export()
      this.data.swiper.animationT = animationT.export()
      this.data.swiper.animationNext = animationNext.export()
      this.setData(this.data)

      this.data.swiper.active = this.data.swiper.active + active
      this.data.answers.activeNum = this.data.answers.activeNum + active
      setTimeout(function () {
        that.setHtmlsetHtml(active)
      }, 300)
    }
  },
  //修改页面至正常位置
  setHtmlsetHtml: function (active) {
    let animationPre = wx.createAnimation({
      transformOrigin: '50% 50%',
      duration: 0,
      timingFunction: 'ease',
      delay: 0
    })
    let animationT = wx.createAnimation({
      transformOrigin: '50% 50%',
      duration: 0,
      timingFunction: 'ease',
      delay: 0
    })
    let animationNext = wx.createAnimation({
      transformOrigin: '50% 50%',
      duration: 0,
      timingFunction: 'ease',
      delay: 0
    })
    animationPre.translate3d('-100%', 0, 0).step()
    animationT.translate3d('0', 0, 0).step()
    animationNext.translate3d('100%', 0, 0).step()

    this.data.swiper.animationPre = animationPre
    this.data.swiper.animationT = animationT
    this.data.swiper.animationNext = animationNext
    this.setData(this.data)

    //调用加载数据方法
    // if ((this.data.swiper.active == 2 && this.data.answers.start > 0) || (this.data.swiper.active + 2 == this.data.answers.list.length && this.data.answers.end < this.data.answers.allList.length)) {
    //   // this.getSubject()
    // }

    //调用滑动结束回调
    if (this.isLockCall && typeof this.isLockCall == 'function') {
      this.isLockCall()
      this.isLockCall = false
    }
    this.$isLock = false
  },
  //获得手势方向
  getDirection: function (startEvent, endEvent) {
    let x = endEvent.changedTouches[0].clientX - startEvent.changedTouches[0].clientX
    let y = endEvent.changedTouches[0].clientY - startEvent.changedTouches[0].clientY
    let pi = 360 * Math.atan(y / x) / (2 * Math.PI)
    if (pi < 25 && pi > -25 && x > 0 && Math.abs(x) > 10) {
      return 'right'
    }
    if (pi < 25 && pi > -25 && x < 0 && Math.abs(x) > 10) {
      return 'left'
    }
    if ((pi < -75 || pi > 750) && y > 0 && Math.abs(y) > 10) {
      return 'bottom'
    }
    if ((pi < -75 || pi > 75) && y < 0 && Math.abs(y) > 10) {
      return 'top'
    }
  },
  getSubject: function () {
    this.data.answers.end = this.data.allList.length
    //注册滑动结束回调
    if (this.$isLock) {
      this.isLockCall = function () {
        this.data.swiper.active = this.data.answers.activeNum - this.data.answers.start
      //  this.data.allList = questionData
        this.data.isLoading = false
        this.setData(this.data)
      }
    } else {
      this.data.swiper.active = this.data.answers.activeNum - this.data.answers.start
     // this.data.allList = questionData
      this.data.isLoading = false
      this.setData(this.data)
    }
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onShow: function () {
    if (app.globalData.userInfo) {
      this.setData({
        userInfo: app.globalData.userInfo,
        hasUserInfo: true
      })
    }
  //  this.data.allList = questionData
    this.data.answers.loading = false
    this.setData(this.data)
    this.countDown()
    this.getSubject()
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {
   
  },

  /**
   * 生命周期函数--监听页面显示
   */
  onLoad: function (e) {
    this.setData({
      origin:e.origin
    })
    if (e.origin.endsWith('4')) {
      this.setData({
        isWenda:true
      })
    }
    if (e.origin=='section') {
      this.setData({
        key:e.key
      })
    }
    wx.showLoading({
      title: '加载中',
    })
    var that = this;
    wx.getStorage({
      key: 'problems',
      success: function(res){
        // success
        that.setData({
          allList:res.data,
          'answers.end':res.data.length
        })
      }
    })
    wx.hideLoading()
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {
     
  },
  changeList: function(list,src) {
    let done=new Array()
    let todo=new Array()
    for (let i=0;i<src.length;i++) {
      if (src[i].isAnswer==1) {
        done.push(src[i])
      } else {
        todo.push(src[i])
      }
    }
    list.splice(0,src.length)
    return todo.concat(list,done)
  },
  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {
    var that =this;
    clearInterval(that.data.timer)
    this.setRecord()
    let list=wx.getStorageSync(this.data.key)
    if (this.data.key!='') {
      let newList=this.changeList(list,this.data.allList)
      wx.setStorage({
        key: this.data.key,
        data: newList,
      })
    }
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