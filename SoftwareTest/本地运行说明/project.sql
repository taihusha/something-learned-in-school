/*
Navicat MySQL Data Transfer

Source Server         : mysql
Source Server Version : 80015
Source Host           : localhost:3306
Source Database       : travel

Target Server Type    : MYSQL
Target Server Version : 80015
File Encoding         : 65001

Date: 2019-11-01 17:34:34
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for comments
-- ----------------------------
DROP TABLE IF EXISTS `comments`;
CREATE TABLE `comments` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(10) NOT NULL,
  `info_id` int(11) NOT NULL,
  `content` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `create_time` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of comments
-- ----------------------------
INSERT INTO `comments` VALUES ('1', '128', '2', '武大真美啊', '2019-11-01 09:52:00');
INSERT INTO `comments` VALUES ('4', '128', '3', '222', '2019-11-01 16:13:02');
INSERT INTO `comments` VALUES ('5', '128', '2', '说点什么吧...', '2019-11-01 16:28:04');
INSERT INTO `comments` VALUES ('6', '128', '2', '武大1', '2019-11-01 16:29:17');
INSERT INTO `comments` VALUES ('7', '128', '4', '辛亥革命', '2019-11-01 16:33:16');
INSERT INTO `comments` VALUES ('8', '128', '4', '革命2', '2019-11-01 16:36:56');
INSERT INTO `comments` VALUES ('9', '128', '4', '革命3', '2019-11-01 16:37:04');
INSERT INTO `comments` VALUES ('10', '129', '1', 'hao a ', '2019-11-01 17:29:17');

-- ----------------------------
-- Table structure for image
-- ----------------------------
DROP TABLE IF EXISTS `image`;
CREATE TABLE `image` (
  `info_id` int(11) DEFAULT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `url` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=61 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of image
-- ----------------------------
INSERT INTO `image` VALUES ('1', '1', 'wKgB21G15QqAfRoYABGSv3hjEck31');
INSERT INTO `image` VALUES ('1', '2', 'wKgBs1bF1leAOVoNAA_CwkMshz422');
INSERT INTO `image` VALUES ('1', '3', 'wKgBs1bF1ruAQzMpAAtDyrWzPIo11');
INSERT INTO `image` VALUES ('1', '4', 'wKgBZ1hzFJeAFfDtAAzBx5g6j5s78');
INSERT INTO `image` VALUES ('1', '5', 'wKgED1vXlSOAL38lACXuhGyB_ng68');
INSERT INTO `image` VALUES ('2', '6', 'wKgED1v4F32AL8F-AA7Wb2MOfwk28');
INSERT INTO `image` VALUES ('2', '7', 'wKgBEFqs9YuAPw3sACUHrWysEyc08');
INSERT INTO `image` VALUES ('2', '8', 'wKgED1xBiv2AMgfVADmP4yDubUU18');
INSERT INTO `image` VALUES ('2', '9', 'wKgBEFqs79aAbNN-ACWtcrs90qk38');
INSERT INTO `image` VALUES ('2', '10', 'wKgBs1bF3JGAXdEIABM33V6lPyE13');
INSERT INTO `image` VALUES ('3', '11', 'wKgBEFq7ca2AF4XzABUHJLgOAs053');
INSERT INTO `image` VALUES ('3', '12', 'wKgED1v63ZSAJabbABQMGJKF5t811');
INSERT INTO `image` VALUES ('3', '13', 'wKgED1uIjo-APTAEABjQHGi41gk09');
INSERT INTO `image` VALUES ('3', '14', 'wKgBZ1mLCY2AfmzwAAyglN26Ank78');
INSERT INTO `image` VALUES ('3', '15', 'wKgBEFq7cgKAahcUABCFMQE-gxc24');
INSERT INTO `image` VALUES ('4', '16', 'wKgED1v8qmOARc5ZACPxTU7S8zU46');
INSERT INTO `image` VALUES ('4', '17', 'wKgED1v8qnCAeiiiACpa6ySbBi849');
INSERT INTO `image` VALUES ('4', '18', 'wKgED1v63ZSAJabbABQMGJKF5t811');
INSERT INTO `image` VALUES ('4', '19', 'wKgED1vXlSOAL38lACXuhGyB_ng68');
INSERT INTO `image` VALUES ('4', '20', 'wKgED1xBiv2AMgfVADmP4yDubUU18');
INSERT INTO `image` VALUES ('5', '21', 'wKgED1vXlSOAL38lACXuhGyB_ng68');
INSERT INTO `image` VALUES ('5', '22', 'wKgED1wTw3iAXWAwADmJWPSlTbU05');
INSERT INTO `image` VALUES ('5', '23', 'wKgED1xBiv2AMgfVADmP4yDubUU18');
INSERT INTO `image` VALUES ('5', '24', 'wKgED1xGerSANn-lAA6HvqqW0Cc82');
INSERT INTO `image` VALUES ('5', '25', 'wKgIDVuHKVqAXzqPACaFPWgL1Bg24');
INSERT INTO `image` VALUES ('6', '26', 'wKgBEFsk1J-AUJIWAAGwvmFT7uw43');
INSERT INTO `image` VALUES ('6', '27', 'wKgBEFsk1KCAOcC-AAZKT0FYSUY82');
INSERT INTO `image` VALUES ('6', '28', 'wKgBEFsk1KGAaX0tAAX8FZqVYKA99');
INSERT INTO `image` VALUES ('6', '29', 'wKgBEFq1viiAYQJaAAnnNVc0wuA87');
INSERT INTO `image` VALUES ('6', '30', 'wKgB3FFdJq6AOKfBAAck3GLQDqM82');
INSERT INTO `image` VALUES ('7', '31', 'wKgBEFqbxtWAMk5iAAp5k-WCt3Q45');
INSERT INTO `image` VALUES ('7', '32', 'wKgED1wsAoaAOqh_AEi7NfJvKnM12');
INSERT INTO `image` VALUES ('7', '33', 'wKgBEFq1vmuAMDlEAA4nNTQ7xcY36');
INSERT INTO `image` VALUES ('7', '34', 'wKgED1uSfYWAXMSzADeg7uaqQ0o07');
INSERT INTO `image` VALUES ('7', '35', 'wKgEaVyYp0qAcuHwAAu0n2XA4nU16');
INSERT INTO `image` VALUES ('8', '36', 'wKgBEFsU6zaAW9SnAAfP7mm6-Q495');
INSERT INTO `image` VALUES ('8', '37', 'wKgBEFsU6zaAKqhZAAntCjrefKI48');
INSERT INTO `image` VALUES ('8', '38', 'wKgBEFsU7DaAfMUnAApac7vdYqI56');
INSERT INTO `image` VALUES ('8', '39', 'wKgBEFsU6zaAaPNXAAV2-WZfKjc45');
INSERT INTO `image` VALUES ('8', '40', 'wKgBEFuDqCSAWE8AAALRBl6Mpng42');
INSERT INTO `image` VALUES ('9', '41', 'wKgEaVzQQCuAK2HQACFUiGrLX7I15');
INSERT INTO `image` VALUES ('9', '42', 'wKgED1xALjaAc_x7AEySIgb_HOA71');
INSERT INTO `image` VALUES ('9', '43', 'wKgED1xALg-AYy--AA1S-pit4kw85');
INSERT INTO `image` VALUES ('9', '44', 'wKgBEFqsZCqAerKvABOz6CZKSrg44');
INSERT INTO `image` VALUES ('9', '45', 'wKgB3FFRcyeATgfKAAtVW6hKWv455');
INSERT INTO `image` VALUES ('10', '46', 'wKgED1uXo2CAOuumAEA5lhx1HJA18');
INSERT INTO `image` VALUES ('10', '47', 'wKgBZ1mHDbSADNHBABQ1CsBiiKc09');
INSERT INTO `image` VALUES ('10', '48', 'wKgB3FFZxSqAdm9-ABL9-fC7Kk450');
INSERT INTO `image` VALUES ('10', '49', 'wKgBs1drWW6AJCzEAAJSr6bkE0o15');
INSERT INTO `image` VALUES ('10', '50', 'wKgE2l1knW-AGuhVAArAcXL5R1Q257.jg');
INSERT INTO `image` VALUES ('11', '51', 'wKgBZ1l40pmAENddAAt78mjHcXI37');
INSERT INTO `image` VALUES ('11', '52', 'wKgBEFtIpNyAO93pAAN3hhPl8JY53');
INSERT INTO `image` VALUES ('11', '53', 'wKgBs1bG1EWAPB1OABGSa52UjYk50');
INSERT INTO `image` VALUES ('11', '54', 'wKgBs1bG1DqAMoQzAAnF9bRVtwQ64');
INSERT INTO `image` VALUES ('11', '55', 'wKgBs1bG0h6ANAUhAA3YPKKU8TM68');
INSERT INTO `image` VALUES ('12', '56', 'wKgBpVV9Vo6ALJ59AAOKRbZM--M71');
INSERT INTO `image` VALUES ('12', '57', 'wKgED1uRQ9eAPtWGAAhSEYFKb2s72');
INSERT INTO `image` VALUES ('12', '58', 'wKgED1uRQ9aAOjzVAAhS1gXkhJ870');
INSERT INTO `image` VALUES ('12', '59', 'wKgED1uMikeAQ80pAAtZy_sZ7qU71');
INSERT INTO `image` VALUES ('12', '60', 'wKgBpVYdKNqAMAvYAAFMhzlpnUY28');

-- ----------------------------
-- Table structure for info
-- ----------------------------
DROP TABLE IF EXISTS `info`;
CREATE TABLE `info` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `summary` text,
  `time` varchar(1000) DEFAULT NULL,
  `traffic` varchar(1000) DEFAULT NULL,
  `ticket` varchar(1000) DEFAULT NULL,
  `open_time` varchar(1000) DEFAULT NULL,
  `location` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of info
-- ----------------------------
INSERT INTO `info` VALUES ('1', '昙华林', '昙华林位于武昌花园山以北、凤凰山以南，东起中山路，西至得胜桥，聚集了许多咖啡店和特色小店。\n1200米的街区集中了几十处百年老建筑，是1371年武昌城扩建定型后逐渐形成的一条老街。\n主要景点包括仁济医院、文华书院、育婴堂万婴墓等，一砖一瓦都刻着老武汉的历史记忆。\n·各流派建筑于此，中西文化交汇，风雨不变百年古街，现已成为武汉的文艺街区，文艺青年们可以来这里拍照、闲逛，再点杯咖啡就悠闲地享受下午的时光。', '1-3小时', '乘坐11 、14、18 、19 、514 、515、521、529、530 、539 、542、554、566 、572 、573 、607路等公交车在司门口站下车即到。', '免费', '全天', '湖北省武汉市武昌区胭脂路昙华林(武昌区东北角,中山路和得胜桥之间)');
INSERT INTO `info` VALUES ('2', '武汉大学', '前身为清末湖广总督张之洞创立的自强学堂，后更名为“国立武汉大学”；濒临东湖，环抱珞珈山，校园内绿树成荫。每每到樱花盛开的季节，朋友圈总会被武汉大学的樱花刷屏。到了武汉大学樱花节，游人争相前往，生怕误了看樱花的好时候。2017年樱花节开始和结束时间是3月14日至3月29日，短短半个月的时间，花期短却繁盛。观赏地点在武汉大学的樱园、樱花大道和樱顶。武汉大学除了高颜值，还是国家首批“985工程”、“211工程”、“2011计划”重点建设高校。颜值和智慧并存，只能羡慕嫉妒恨了。\n樱花名声远扬，校园内有樱花城堡、樱花大道、樱顶、珞珈广场等主要赏樱地点；其中，“老斋舍”前的“樱花大道”，是武大赏樱的好去处。除了樱花，更值得一看的是一幢幢的老建筑；珞珈山腰东南的教工住宅群，建筑风格整体采用了英式乡间别墅风格，每一栋都自有其特点。', '1-3小时', '乘坐317、413、515、519、552、564、572、587、591、608、724路公交车在八一路珞珈山站下车即可到达。', '免费', '全天', '湖北省武汉市武昌区八一路299号');
INSERT INTO `info` VALUES ('3', '汉阳造艺术区', '这里也叫824创意工厂，充满了旧工业时代的气息，高架的行车、悬空的工业排风扇等，还有随处可见的涂鸦、行为艺术、创意 雕塑。当年这里是汉阳兵工厂和824工厂的一部分，如今这里是喜欢自拍的文青们的必到之处。艺术区位于武汉市龟山脚下，聚集着众多的艺术工作室、画廊和书店，也有不少咖啡馆、饭店等。旧工业改商业和艺术创作园区的典范，足够新颖，足够创新，供艺术家们发挥无限的创作力与想象力。', '1-3小时', '乘坐10/64/507/524/542/598/608/609/701/703/705/706/806至鹦鹉大道古琴台，即可到达', '免费', '全天', '湖北省武汉市汉阳区龟北路1号');
INSERT INTO `info` VALUES ('4', '黎黄陂路街头博物馆', '以辛亥革命领导人黎元洪来命名的，黎黄陂路两侧仍保留了大约17处租界时代遗留的欧式建筑。汉口开埠后列强涌入划分租界，建立领事馆、洋行，呈现一派殖民色彩的畸形繁荣，成为殖民者们乐而忘返的“东方芝加哥”。租界中心的黎黄陂路是这段屈辱历史的缩影。如今黎黄陂路街头博物馆包括十七处古建筑，在街头与街尾都立有碑牌标示。', '3-4小时', '乘坐559、588、598、707、711路在黎黄陂路站下车。', '免费', '全天', '湖北省武汉市江岸区沿江大道162');
INSERT INTO `info` VALUES ('5', '古德寺', '古德寺位于汉口黄浦路上滑坡，以独特的异域风情最为著名。寺内最主要的建筑为圆通宝殿，宝殿上的装饰、佛像及九座佛塔和塔刹，都为人惊叹和赞美。回形步廊、莲花方墩等充满佛教流派精髓，也将印度和东南亚各国的帕那瓦建筑风格全面展现。取“心性好古，普度以德”之意，佛殿仿照缅甸阿难陀寺建造，是一座具有浓郁异域建筑风格的寺庙。是汉传佛教唯一、世界仅存两座此类风格的佛教建筑之一，具有重要的宗教、建筑和文化历史价值。隐匿在城市的高楼中，是一个很多武汉人都不知道的地方，香客极少，可谓真正的佛门清净地。', '1-3小时', '乘坐30/电3路/电2路至工农兵路国宾酒店站；乘坐轻轨1号线至头道街站，即可到达', '免费', '07:00-17:30 (1月1日-12月31日 周一-周日)', '湖北省武汉市江岸区工农兵路74号');
INSERT INTO `info` VALUES ('6', '光谷步行街', '世界城光谷步行街全长1390米，位于武汉市武昌区鲁巷广场，是一条建设在以鲁巷为中心的光谷核心地段上的全球第一步行街，由一条1350米的目前世界最长纯步行商业街串起，其中第二期-西班牙风情街，具有清朗明丽的地中海风情，兼具古典气息与现代时尚的建筑群相辉映，浓郁的西班牙风情错落隐现，具有奢华雅致的欧洲商街风格。建筑、雕塑小品与商业完美交融，逛街的趣味感油然而生，沉醉其中宛若穿行于另一个时空。', '3-5小时', '乘5路; 340路; 518路; 518路通宵车; 521路; 591路; 613路; 755路; 756路; 785路; 786路; 789路; 909路到珞喻路光谷广场下车即到。或者乘坐地铁2号线到光谷，步行几百米即到。', '免费', '全天', '湖北省武汉市洪山区珞瑜路726号');
INSERT INTO `info` VALUES ('7', '403国际艺术中心', '403国际艺术中心落地于湖北省武汉市武昌区中南路街武珞路586号百瑞景中央生活区，由原武汉锅炉厂编号403双层车间的工业遗址改造而成。403国际艺术中心致力于打造成为国际品牌艺术中心，新潮先锋文化艺术地标，文化创意跨界融合发展示范区。这里将成为一个真正的文化艺术发生的场所，一个以吸引、聚合、孵化文创精英为理念的人才高地，一个致力于跨界整合资源，鼓励创新原创的实践平台，一个真正让创意发声，让文艺活化的新青年舞台，一个具有原创性的独立品牌的联合平台。中心开设了红椅先锋剧场、漫行咖啡书吧、留白艺术中心、原型创意创业帮四大板块，将旋转的墙、穿透的书柜、移动的家居等融为一体，部分装饰物、展览台直接就是遗留的工业设备，十分有创意。', '1-3小时', '乘坐320路至宝通寺路艺术中心站；乘坐59路/66路/401路/510路/518路/518路通宵车/518区/519路/538路/576路/583路/593路/596路至武珞路洪山站；乘坐轨道交通2号线至宝通寺站，即可到达', '免费', '10:00-21:00 (1月1日-12月31日 周一-周日)', '湖北省武汉市武昌区宝通寺路33号百瑞景中央生活区');
INSERT INTO `info` VALUES ('8', '界立方创意空间', '界立方创意空间位于武汉市江岸区，由5栋砖木结构的老厂房改建而成。这里曾是俄商“新泰洋行”旧址，后来又被改建成为百货公司、物质仓库、菜市场等，如今成为创意空间，焕发了新的生机。如今这里已已成为武汉人眼中最有文艺范的休闲去处。创意空间保留了老厂房原有的老砖墙、门洞和木梁等，带着一份历史的沉淀与岁月的凝重。空间分为外街、内街、后街三个区域，外街主打欧式风情，以餐饮为主；内街位于天井的正下面，以各色主题店为主，老砖老墙，非常小资；后街是带入户花园的LOFT结构，以各类精致主题会所为主。界立方的二楼入驻的都是文化、创意、艺术类的机构，极具艺术气息。', '1-3小时', '乘公交7路、30路、68路、212路、502路、523路、527路、579路、601路、606路、708路、721路到沿江大道兰陵路站下可到。', '免费', '08:00-17:00 (1月1日-12月31日 周一-周日)', '湖北省武汉市江岸区沿江大道合作路14号');
INSERT INTO `info` VALUES ('9', '关山荷兰风情园', '荷兰风情园总占地面积近8万平方米，其中人工湖约4800平方米。公园大体呈梯形，东西长约340米，南北宽约190－250米。人工湖位于公园中央，湖边西面除了大面积种植郁金香与风信子外，还有源自欧洲大陆的西洋樱草、金盏菊、三色堇、花毛茛等花卉。整个风情园花卉总量超过45万盆。\r\n武汉荷兰风情园位于洪山区民族大道东侧，武汉科技学院以北。武汉市园林局介绍，此处原为关山公园，去年2月武汉市政府决定将其建设成为荷兰风情园，作为该市与荷兰阿纳姆市友好交流的历史见证。\r\n大风车无疑成为荷兰风情园的一大亮点。进入荷兰风情园，高耸的大风车直入眼帘。这个大风车高13米，扇叶半径为7米，风车转动时最高点可达到21米。', '1-3小时', '乘公交25路、362路、405路、538路、572路、583路、586路、590路、732路、739路、759路、810路、811路在民族大道当代学生公寓站下即可到达', '免费', '全天', '湖北省武汉市洪山区民族大道163号(光谷时间广场对面)');
INSERT INTO `info` VALUES ('10', '古琴台', '古琴台占地约1公顷，掩映在湖光山色、疏林繁花之中，瑰丽多姿。秋天的氛围里，当年高山流水遇知音的故事显得更加凄美。相传是俞伯牙和钟子期“高山流水遇知音”相遇在此，与黄鹤楼、晴川阁并称为“三楚胜境”，\n殿堂前琴台为汉白玉筑成的方形石台，相传为伯牙抚琴之处，有“天下知音第一台”之称。\n·除主建筑还有庭院、林园、花坛、茶室等，布局精巧、层次分明。', '1小时以下', '乘坐10、 64、507、 524、542、598、608、609、701、703、705、706、806在鹦鹉大道古琴台站下车然后步行400米即可到达。', 'summary', '08:00-17:00 (1月1日-12月31日 周一-周日)', '湖北省武汉市汉阳区琴台大道10号');
INSERT INTO `info` VALUES ('11', '晴川阁', '晴川阁坐落在武汉市汉阳龟山东麓禹功矶上，北临汉水，东濒长江，与黄鹤楼夹江相望，是武汉地区唯一一处临江而立的名胜古迹。整个占地约一万平方米，平面呈三角形，由晴川阁、禹稷行宫、铁门关三大主体建筑和禹碑亭、朝宗亭、楚波亭、荆楚雄风碑、曲径回廊等十几处附属建筑组成。 晴川阁，又名晴川楼，该阁自创建以来，几经兴废。复建后的晴川阁占地386平方米，高17.5米，重檐歇山顶式，麻石台基，红墙朱柱，钢筋混凝土仿木结构。整个楼阁分上下两层，沿檐回廊，原汁原味地再现了楚人依山就势筑台，台上建楼阁的雄奇风貌。 晴川阁以南方建筑风格为主，融合南北建筑风格之长，使楼阁的雄奇、行宫的古朴、园林的秀美浑为一体，成为武汉市著名的文物旅游景观。', '1小时以下', '乘坐30/108/248/531/532/535/553/559/561/648/711/803路至晴川阁站，即可到达', '免费', '09:00-17:00；停止入场时间:16:30 (1月1日-12月31日 周一-周三,周五-周日)09:00-15:00 (1月1日-12月31日 周四)', '湖北省武汉市汉阳区洗马长街86号');
INSERT INTO `info` VALUES ('12', '江城壹号创意园', '由旧车厂改造。门口那个彩色废旧汽车“叠罗汉”的雕塑，文艺青年应该没有谁不知道吧。虽然入住了不少商家，但是远没闹市区热闹拥挤。因是厂，空间很开阔，红墙也是文艺到骨子里。\"江城一号\"文化创意产业园是新中国第一台手扶拖拉机的诞生地，28幢苏式老厂房历经半个多世纪的风雨冲刷，已演变为\"武汉制造\"的工业遗址，园内一尊10米多高、由13辆五颜六色的报废轿车叠罗汉形成的雕塑亮相武汉。', '1-3小时', '乘坐119路公交至南泥湾大道古田四路下车，步行10分钟即可到达', '免费', '09:00-17:30 (1月1日-12月31日 周一-周日)', '湖北省武汉市硚口古田四路与南泥湾大道交叉处');

-- ----------------------------
-- Table structure for like_tab
-- ----------------------------
DROP TABLE IF EXISTS `like_tab`;
CREATE TABLE `like_tab` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `user_id` int(10) NOT NULL,
  `scene_id` int(10) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of like_tab
-- ----------------------------
INSERT INTO `like_tab` VALUES ('3', '124', '1');
INSERT INTO `like_tab` VALUES ('6', '128', '3');
INSERT INTO `like_tab` VALUES ('9', '128', '2');
INSERT INTO `like_tab` VALUES ('10', '128', '4');
INSERT INTO `like_tab` VALUES ('13', '129', '3');
INSERT INTO `like_tab` VALUES ('15', '129', '1');
INSERT INTO `like_tab` VALUES ('18', '128', '1');

-- ----------------------------
-- Table structure for user_tab
-- ----------------------------
DROP TABLE IF EXISTS `user_tab`;
CREATE TABLE `user_tab` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(100) NOT NULL,
  `password` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=131 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of user_tab
-- ----------------------------
INSERT INTO `user_tab` VALUES ('123', '123123aa', '123123aa');
INSERT INTO `user_tab` VALUES ('124', 'lzl123', '123123aa');
INSERT INTO `user_tab` VALUES ('125', 'lzl123a', '123123aa');
INSERT INTO `user_tab` VALUES ('126', 'wbc1996', 'wbc1996');
INSERT INTO `user_tab` VALUES ('128', 'zhaokw1', 'zhaokw1');
INSERT INTO `user_tab` VALUES ('129', 'zhaokw2', 'zhaokw2');
INSERT INTO `user_tab` VALUES ('130', 'zhaokw3', 'zhaokw3');
