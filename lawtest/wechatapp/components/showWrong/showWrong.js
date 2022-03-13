// packageA/pages/component/showWrong/showWrong.js
Component({
  /**
   * 组件的属性列表
   */
  properties: {
    modalShow: {
      type: Boolean,
      value: false
    },
    // 错题题序集合
    wrongProblem: {
      type: Object,
      value: {}
    },
    scrollHeight:Number
  },
  //数据监听器
  observers:{
     "modalShow":function(modalShow){
       if(modalShow==true){
        var query  = this.createSelectorQuery()
        var that = this
        query.select('.modal-title').boundingClientRect()
        query.select('.deleteButton').boundingClientRect()
        query.exec(function(res){
           that.setData({
               scrollHeight: res[1].bottom - res[0].top
           })
           wx.getSystemInfo({
            success:function (res) {
              let scale =  750 / res.windowWidth; //将高度乘以换算后的该设备的rpx与px的比例
              if(that.data.scrollHeight>0.8*res.windowHeight){
                that.setData({
                  scrollHeight: 0.8*res.windowHeight*scale
                })
              }
              else{
                that.setData({
                  scrollHeight: that.data.scrollHeight*scale
                })
              }
            }
          }) 
        })
         
       }
     }
  },

  /**
   * 组件的初始数据
   */
  data: {
     
  },

  /**
   * 组件的方法列表
   */
  methods: {
    closeModal:function(){
      this.setData({
        modalShow: !this.data.modalShow
      })
    },  
    radioChange:function(e){
      var items = this.data.wrongProblem
      for (let i = 0, len = items.options.length; i < len; ++i) {
        items.options[i].checked = items.options[i].label === e.detail.value
      }
      this.setData({
        wrongProblem:items
      })

    },
    checkBoxChange:function(e){
      var items = this.data.wrongProblem
      var values = e.detail.value
      for (let i = 0, lenI = items.options.length; i < lenI; ++i) {
        items.options[i].checked = false
        for (let j = 0, lenJ = values.length; j < lenJ; ++j) {
          if (items.options[i].label === values[j]) {
            items.options[i].checked = true
            break
          }
        }
      }
      this.setData({
        wrongProblem:items
      })
    },
    //提交确认函数
    confirmButton: function(e){
      var items = this.data.wrongProblem
      var str = ""
      for(let i = 0, len = items.options.length; i<len; ++i){
          if(items.options[i].checked == true){
            str = str + items.options[i].label;
          }
      }
      if(str != ""){
        if(str == items.a){
          wx.showToast({
            title:"恭喜你答对了这题",
            duration: 1000,
            icon:"none"
          })
          items.isAnswer = 1
        }
        else{
         wx.showModal({
           title:"对不起，你答错了",
           content:"正确答案是" + items.a,
           showCancel: false
         })
          items.isAnswer = 2
        }
        items.choose=str
        this.setData({
          wrongProblem:items
        })
      }
      else{
        wx.showToast({
          title:"你未解答该问题",
          duration: 1000,
          icon:"none"
        })
      }
    },
    //移除错题库
    deleteButton: function(e){
      var that = this
      wx.showModal({
        title: '提示',
        content: '是否确定将该题移出当前列表',
        success (res) {
          if (res.confirm) {
            var myEventDetail = {index:that.data.wrongProblem.Id} // detail对象，提供给事件监听函数
            var myEventOption = {} // 触发事件的选项
            that.triggerEvent('myevent', myEventDetail, myEventOption)
            wx.showToast({
              title:"已移出当前列表",
              duration: 1000,
              icon:"none"
            })
            that.setData({
              modalShow: !that.data.modalShow,
            })
           } 
           else if (res.cancel) {
            wx.showToast({
              title:"题目仍在当前列表",
              duration: 1000,
              icon:"none"
            })
          }
        }
      })
    }
  }
})
