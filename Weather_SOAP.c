Action()
{
	
	soap_request("StepName=SOAP Request",										
		"URL=http://www.webxml.com.cn/WebServices/WeatherWebService.asmx",										
		"SOAPEnvelope="
		"<soap:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\">"
			"<soap:Body>"
				"<getWeatherbyCityName xmlns=\"http://WebXml.com.cn/\">"
					"<theCityName>涓婃捣</theCityName>"//如果输入上海,由于编码问题不能被识别,默认城市为北京
				"</getWeatherbyCityName>"
			"</soap:Body>"
		"</soap:Envelope>",										
		"SOAPAction=http://WebXml.com.cn/getWeatherbyCityName",										
		"ResponseParam=response",										
		"Snapshot=t1396577124.inf",									    
		LAST);
	//lr_convert_string_encoding(lr_eval_string("{response}"),LR_ENC_UTF8 ,NULL, "result");
	//lr_output_message(lr_eval_string("{result}"));

	lr_xml_get_values("XML={response}",
					  "ValueParam=ParamValue_string",
					  "Query=/Envelope/Body/getWeatherbyCityNameResponse/getWeatherbyCityNameResult/string[2]",
					  LAST);
	lr_output_message(lr_eval_string("{ParamValue_string}"));
	//比较截取的字符串是不是上海

	if(strcmp("上海",lr_eval_string("{ParamValue_string}"))==0){
		lr_output_message("-------------结果正确!!-----------------");
	}else{
		lr_output_message("-------------结果错误!!-----------------");
	}

	return 0;
}
