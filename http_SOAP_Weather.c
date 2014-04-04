Action()
{
	//SOAP1.1的写法
// 	web_add_header("Content-Type","text/xml; charset=utf-8");
// 	web_custom_request("web_custom_request",
// 					   "URL=http://www.webxml.com.cn/WebServices/WeatherWebService.asmx",
// 					   "Method=POST",
// 					   "Resource=0",
// 					   "Body=<?xml version=\"1.0\" encoding=\"utf-8\"?>"
// 					   "<soap:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\">"
// 						   "<soap:Body>"
// 							"<getWeatherbyCityName xmlns=\"http://WebXml.com.cn/\">"
// 								"<theCityName>上海</theCityName>"
// 							"</getWeatherbyCityName>"
// 						   "</soap:Body>"
// 						 "</soap:Envelope>",
// 						LAST);
	//SOAP1.2的写法
	web_add_header("Content-Type","application/soap+xml; charset=utf-8");
	//使用关联函数找到所有的代码
	web_reg_save_param_ex("ParamName=getcityid",
						  "LB=,",
						  "RB=</string>",
						  "Ordinal=ALL",
						  "SEARCH_FILTERS",
						  "Scope=BODY",
						  LAST);
	web_custom_request("web_custom_request",
 					   "URL=http://www.webxml.com.cn/WebServices/WeatherWS.asmx",
 					   "Method=POST",
 					   "Resource=0",
					   "Body=<?xml version=\"1.0\" encoding=\"utf-8\"?>"
                       "<soap12:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap12=\"http://www.w3.org/2003/05/soap-envelope\">"
						   "<soap12:Body>"
								"<getSupportCityString xmlns=\"http://WebXml.com.cn/\">"
									"<theRegionCode>涓婃捣</theRegionCode>"//上海 UTF-8
								"</getSupportCityString>"
							"</soap12:Body>"
						"</soap12:Envelope>",
					   "Snapshot=t1.inf",
					   LAST);
										  
   
	return 0;
}
