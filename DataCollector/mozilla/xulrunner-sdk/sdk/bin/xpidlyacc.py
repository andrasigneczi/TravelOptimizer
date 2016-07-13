
# ../../xpcom/idl-parser\xpidlyacc.py
# This file is automatically generated. Do not edit.
_tabversion = '3.2'

_lr_method = 'LALR'

_lr_signature = ',Q\xe7:m\xcf|\xa4\x8ad\x0f\x06\xc1Q\x1f\x99'
    
_lr_action_items = {'CONST':([6,25,42,47,48,82,84,104,],[14,14,45,45,-28,-29,-41,-42,]),'NATIVEID':([43,],[50,]),'NUMBER':([62,65,66,77,78,79,80,81,83,],[68,68,68,68,68,68,68,68,68,]),'LSHIFT':([67,68,69,70,75,76,92,93,94,95,96,97,98,],[80,-30,-32,-31,80,-34,-33,-35,-37,-36,-38,-39,80,]),'RSHIFT':([67,68,69,70,75,76,92,93,94,95,96,97,98,],[81,-30,-32,-31,81,-34,-33,-35,-37,-36,-38,-39,81,]),'INOUT':([28,64,74,85,],[-13,-14,90,-14,]),'NATIVE':([0,2,5,7,8,9,10,28,31,44,61,],[-14,-14,-14,-14,-14,-14,23,-13,-8,-21,-9,]),')':([33,34,50,64,68,69,70,72,73,75,76,86,92,93,94,95,96,97,98,99,103,106,107,108,111,],[38,39,57,-44,-30,-32,-31,-45,87,92,-34,-43,-33,-35,-37,-36,-38,-39,-40,-45,-46,-47,109,-55,-56,]),'(':([14,16,17,30,37,60,62,65,66,77,78,79,80,81,83,101,],[-12,27,-11,-10,43,64,65,65,65,65,65,65,65,65,65,105,]),'+':([67,68,69,70,75,76,92,93,94,95,96,97,98,],[77,-30,-32,-31,77,-34,-33,-35,-37,-36,77,77,77,]),'*':([67,68,69,70,75,76,92,93,94,95,96,97,98,],[78,-30,-32,-31,78,-34,-33,78,-37,78,78,78,78,]),'-':([62,65,66,67,68,69,70,75,76,77,78,79,80,81,83,92,93,94,95,96,97,98,],[66,66,66,79,-30,-32,-31,79,-34,66,66,66,66,66,66,-33,-35,-37,-36,79,79,79,]),',':([14,15,16,17,26,38,39,72,99,106,108,],[-12,25,-20,-11,-17,-18,-19,85,85,-47,110,]),'IID':([27,],[34,]),'READONLY':([28,42,47,48,49,82,84,104,],[-13,-14,-14,-28,55,-29,-41,-42,]),';':([24,29,36,40,41,52,57,67,68,69,70,71,76,87,92,93,94,95,96,97,98,100,109,],[31,-25,-23,-24,44,-22,61,82,-30,-32,-31,84,-34,-54,-33,-35,-37,-36,-38,-39,-40,104,-53,]),'IDENTIFIER':([3,6,12,22,23,25,27,28,35,42,45,47,48,49,51,56,59,62,63,65,66,77,78,79,80,81,82,83,84,88,89,90,91,102,104,105,110,],[12,17,24,29,30,17,33,-13,40,-14,51,-14,-28,56,58,60,63,69,71,69,69,69,69,69,69,69,-29,69,-41,102,-48,-49,-50,106,-42,108,108,]),'=':([58,],[62,]),'OUT':([28,64,74,85,],[-13,-14,91,-14,]),'TYPEDEF':([0,2,5,7,8,9,31,44,61,],[3,3,3,3,3,3,-8,-21,-9,]),'RAISES':([87,],[101,]),'IN':([28,64,74,85,],[-13,-14,89,-14,]),'[':([0,2,5,7,8,9,31,42,44,47,48,61,64,82,84,85,104,],[6,6,6,6,6,6,-8,6,-21,6,-28,-9,6,-29,-41,6,-42,]),'INCLUDE':([0,2,5,7,8,9,31,44,61,],[7,7,7,7,7,7,-8,-21,-9,]),']':([14,15,16,17,18,26,32,38,39,],[-12,-15,-20,-11,28,-17,-16,-18,-19,]),':':([29,],[35,]),'ATTRIBUTE':([28,42,47,48,49,54,55,82,84,104,],[-13,-14,-14,-28,-52,59,-51,-29,-41,-42,]),'CDATA':([0,2,5,7,8,9,31,42,44,47,48,61,82,84,104,],[9,9,9,9,9,9,-8,48,-21,48,-28,-9,-29,-41,-42,]),'INTERFACE':([0,2,5,7,8,9,10,28,31,44,61,],[-14,-14,-14,-14,-14,-14,22,-13,-8,-21,-9,]),'{':([29,36,40,],[-25,42,-24,]),'$end':([0,1,2,4,5,7,8,9,11,13,19,20,21,31,44,61,],[-2,-1,-2,0,-2,-2,-2,-2,-6,-5,-4,-7,-3,-8,-21,-9,]),'}':([42,46,47,48,53,82,84,104,],[-26,52,-26,-28,-27,-29,-41,-42,]),'|':([67,68,69,70,75,76,92,93,94,95,96,97,98,],[83,-30,-32,-31,83,-34,-33,-35,-37,-36,-38,-39,-40,]),'HEXNUM':([62,65,66,77,78,79,80,81,83,],[70,70,70,70,70,70,70,70,70,]),}

_lr_action = { }
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = { }
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'members':([42,47,],[46,53,]),'attribute':([6,25,],[15,15,]),'number':([62,65,66,77,78,79,80,81,83,],[67,75,76,93,94,95,96,97,98,]),'productions':([0,2,5,7,8,9,],[1,11,13,19,20,21,]),'raises':([87,],[100,]),'ifacebody':([36,],[41,]),'attlist':([6,25,],[18,32,]),'native':([0,2,5,7,8,9,],[8,8,8,8,8,8,]),'typedef':([0,2,5,7,8,9,],[2,2,2,2,2,2,]),'attributeval':([16,],[26,]),'optreadonly':([49,],[54,]),'ifacebase':([29,],[36,]),'afternativeid':([30,],[37,]),'param':([64,85,],[72,99,]),'member':([42,47,],[47,47,]),'idlfile':([0,],[4,]),'paramlist':([64,],[73,]),'moreparams':([72,99,],[86,103,]),'interface':([0,2,5,7,8,9,],[5,5,5,5,5,5,]),'idlist':([105,110,],[107,111,]),'paramtype':([74,],[88,]),'anyident':([6,25,],[16,16,]),'attributes':([0,2,5,7,8,9,42,47,64,85,],[10,10,10,10,10,10,49,49,74,74,]),}

_lr_goto = { }
for _k, _v in _lr_goto_items.items():
   for _x,_y in zip(_v[0],_v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = { }
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> idlfile","S'",1,None,None,None),
  ('idlfile -> productions','idlfile',1,'p_idlfile','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1098),
  ('productions -> <empty>','productions',0,'p_productions_start','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1102),
  ('productions -> CDATA productions','productions',2,'p_productions_cdata','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1106),
  ('productions -> INCLUDE productions','productions',2,'p_productions_include','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1111),
  ('productions -> interface productions','productions',2,'p_productions_interface','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1116),
  ('productions -> typedef productions','productions',2,'p_productions_interface','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1117),
  ('productions -> native productions','productions',2,'p_productions_interface','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1118),
  ('typedef -> TYPEDEF IDENTIFIER IDENTIFIER ;','typedef',4,'p_typedef','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1123),
  ('native -> attributes NATIVE IDENTIFIER afternativeid ( NATIVEID ) ;','native',8,'p_native','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1130),
  ('afternativeid -> <empty>','afternativeid',0,'p_afternativeid','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1137),
  ('anyident -> IDENTIFIER','anyident',1,'p_anyident','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1143),
  ('anyident -> CONST','anyident',1,'p_anyident','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1144),
  ('attributes -> [ attlist ]','attributes',3,'p_attributes','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1149),
  ('attributes -> <empty>','attributes',0,'p_attributes','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1150),
  ('attlist -> attribute','attlist',1,'p_attlist_start','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1158),
  ('attlist -> attribute , attlist','attlist',3,'p_attlist_continue','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1162),
  ('attribute -> anyident attributeval','attribute',2,'p_attribute','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1167),
  ('attributeval -> ( IDENTIFIER )','attributeval',3,'p_attributeval','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1171),
  ('attributeval -> ( IID )','attributeval',3,'p_attributeval','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1172),
  ('attributeval -> <empty>','attributeval',0,'p_attributeval','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1173),
  ('interface -> attributes INTERFACE IDENTIFIER ifacebase ifacebody ;','interface',6,'p_interface','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1178),
  ('ifacebody -> { members }','ifacebody',3,'p_ifacebody','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1207),
  ('ifacebody -> <empty>','ifacebody',0,'p_ifacebody','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1208),
  ('ifacebase -> : IDENTIFIER','ifacebase',2,'p_ifacebase','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1213),
  ('ifacebase -> <empty>','ifacebase',0,'p_ifacebase','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1214),
  ('members -> <empty>','members',0,'p_members_start','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1219),
  ('members -> member members','members',2,'p_members_continue','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1223),
  ('member -> CDATA','member',1,'p_member_cdata','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1228),
  ('member -> CONST IDENTIFIER IDENTIFIER = number ;','member',6,'p_member_const','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1232),
  ('number -> NUMBER','number',1,'p_number_decimal','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1240),
  ('number -> HEXNUM','number',1,'p_number_hex','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1245),
  ('number -> IDENTIFIER','number',1,'p_number_identifier','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1250),
  ('number -> ( number )','number',3,'p_number_paren','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1256),
  ('number -> - number','number',2,'p_number_neg','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1260),
  ('number -> number + number','number',3,'p_number_add','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1265),
  ('number -> number - number','number',3,'p_number_add','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1266),
  ('number -> number * number','number',3,'p_number_add','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1267),
  ('number -> number LSHIFT number','number',3,'p_number_shift','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1278),
  ('number -> number RSHIFT number','number',3,'p_number_shift','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1279),
  ('number -> number | number','number',3,'p_number_bitor','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1288),
  ('member -> attributes optreadonly ATTRIBUTE IDENTIFIER IDENTIFIER ;','member',6,'p_member_att','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1294),
  ('member -> attributes IDENTIFIER IDENTIFIER ( paramlist ) raises ;','member',8,'p_member_method','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1310),
  ('paramlist -> param moreparams','paramlist',2,'p_paramlist','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1325),
  ('paramlist -> <empty>','paramlist',0,'p_paramlist','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1326),
  ('moreparams -> <empty>','moreparams',0,'p_moreparams_start','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1334),
  ('moreparams -> , param moreparams','moreparams',3,'p_moreparams_continue','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1338),
  ('param -> attributes paramtype IDENTIFIER IDENTIFIER','param',4,'p_param','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1343),
  ('paramtype -> IN','paramtype',1,'p_paramtype','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1351),
  ('paramtype -> INOUT','paramtype',1,'p_paramtype','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1352),
  ('paramtype -> OUT','paramtype',1,'p_paramtype','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1353),
  ('optreadonly -> READONLY','optreadonly',1,'p_optreadonly','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1357),
  ('optreadonly -> <empty>','optreadonly',0,'p_optreadonly','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1358),
  ('raises -> RAISES ( idlist )','raises',4,'p_raises','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1365),
  ('raises -> <empty>','raises',0,'p_raises','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1366),
  ('idlist -> IDENTIFIER','idlist',1,'p_idlist','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1373),
  ('idlist -> IDENTIFIER , idlist','idlist',3,'p_idlist_continue','c:\\builds\\moz2_slave\\rel-m-rel-xr_w32_bld-000000000\\build\\xpcom\\idl-parser\\xpidl.py',1377),
]