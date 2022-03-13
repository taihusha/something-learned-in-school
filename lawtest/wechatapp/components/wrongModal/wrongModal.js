// components/wrongModal/wrongModal.js
Component({
    /**
     * 组件的属性列表
     */
    properties: {
      // 是否显示
      modalShow: {
        type: Boolean,
        value: false
      },
      // 错题题序集合
      wrongProblem: {
        type: Object,
        value: {}
      },
      isWenda:{
        type:Boolean,
        value:false
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
      // 关闭弹窗
      closeModal: function () {
        this.setData({
          modalShow: false
        })
      },
    }
  })