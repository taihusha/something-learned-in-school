package routers

import (
	"github.com/astaxie/beego"
	"github.com/astaxie/beego/context/param"
)

func init() {

    beego.GlobalControllerRouter["lawtest/controllers:KlpController"] = append(beego.GlobalControllerRouter["lawtest/controllers:KlpController"],
        beego.ControllerComments{
            Method: "Get",
            Router: "/Klp",
            AllowHTTPMethods: []string{"get"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:KlpController"] = append(beego.GlobalControllerRouter["lawtest/controllers:KlpController"],
        beego.ControllerComments{
            Method: "GetContent",
            Router: "/Klp/:chapter/:type",
            AllowHTTPMethods: []string{"get"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:PageController"] = append(beego.GlobalControllerRouter["lawtest/controllers:PageController"],
        beego.ControllerComments{
            Method: "GetPages",
            Router: "/page",
            AllowHTTPMethods: []string{"get"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:PageController"] = append(beego.GlobalControllerRouter["lawtest/controllers:PageController"],
        beego.ControllerComments{
            Method: "GetPageByYearType",
            Router: "/page/:year/:type",
            AllowHTTPMethods: []string{"get"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:PracticeController"] = append(beego.GlobalControllerRouter["lawtest/controllers:PracticeController"],
        beego.ControllerComments{
            Method: "AddPractice",
            Router: "/addpracice",
            AllowHTTPMethods: []string{"post"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:PracticeController"] = append(beego.GlobalControllerRouter["lawtest/controllers:PracticeController"],
        beego.ControllerComments{
            Method: "GetPractice",
            Router: "/getpracice",
            AllowHTTPMethods: []string{"get"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:PracticeController"] = append(beego.GlobalControllerRouter["lawtest/controllers:PracticeController"],
        beego.ControllerComments{
            Method: "Get",
            Router: "/practice",
            AllowHTTPMethods: []string{"get"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:PracticeController"] = append(beego.GlobalControllerRouter["lawtest/controllers:PracticeController"],
        beego.ControllerComments{
            Method: "AddColletion",
            Router: "/practice/addcollection",
            AllowHTTPMethods: []string{"post"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:PracticeController"] = append(beego.GlobalControllerRouter["lawtest/controllers:PracticeController"],
        beego.ControllerComments{
            Method: "AddWrong",
            Router: "/practice/addwrong",
            AllowHTTPMethods: []string{"post"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:PracticeController"] = append(beego.GlobalControllerRouter["lawtest/controllers:PracticeController"],
        beego.ControllerComments{
            Method: "DeleteCollection",
            Router: "/practice/deletecollection",
            AllowHTTPMethods: []string{"post"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:PracticeController"] = append(beego.GlobalControllerRouter["lawtest/controllers:PracticeController"],
        beego.ControllerComments{
            Method: "DeleteWrong",
            Router: "/practice/deletewrong",
            AllowHTTPMethods: []string{"post"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:UserController"] = append(beego.GlobalControllerRouter["lawtest/controllers:UserController"],
        beego.ControllerComments{
            Method: "GetDifficult",
            Router: "/user/getCollecion",
            AllowHTTPMethods: []string{"get"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

    beego.GlobalControllerRouter["lawtest/controllers:UserController"] = append(beego.GlobalControllerRouter["lawtest/controllers:UserController"],
        beego.ControllerComments{
            Method: "GetWrong",
            Router: "/user/getWrong",
            AllowHTTPMethods: []string{"get"},
            MethodParams: param.Make(),
            Filters: nil,
            Params: nil})

}
