Action()
{
	char *citystring;
	int stringlen;
	char *temp;
	
	web_service_call( "StepName=getSupportCityString_101",
		"SOAPMethod=WeatherWS|WeatherWSSoap|getSupportCityString",
		"ResponseParam=response",
		"Service=WeatherWS",
		"ExpectedResponse=SoapResult",
		"Snapshot=t1396495459.inf",
		BEGIN_ARGUMENTS,
		"theRegionCode=北京",
		END_ARGUMENTS,
		BEGIN_RESULT,
		END_RESULT,
		LAST);

	lr_xml_get_values("XML={response}",
					  "ValueParam=ParamValue_string",
					  "Query=/Envelope/Body/getSupportCityStringResponse/getSupportCityStringResult/string[10]",
					  LAST);
	lr_output_message(lr_eval_string("{ParamValue_string}"));
	citystring = lr_eval_string("{ParamValue_string}");
	stringlen = strlen(citystring)-4;
	lr_output_message("--------%d-----", stringlen);
	lr_save_var(citystring+stringlen, 4, 0, "citycode");
	lr_output_message(lr_eval_string("{citycode}"));

    

	web_service_call( "StepName=getWeather_102",
		"SOAPMethod=WeatherWS|WeatherWSSoap|getWeather",
		"ResponseParam=response1",
		"Service=WeatherWS",
		"ExpectedResponse=SoapResult",
		"Snapshot=t1396517195.inf",
		BEGIN_ARGUMENTS,
		"theCityCode={citycode}",
		END_ARGUMENTS,
		BEGIN_RESULT,
		END_RESULT,
		LAST);

    lr_convert_string_encoding(lr_eval_string("{response1}"), LR_ENC_UTF8 , NULL, "result");
	lr_output_message("# 服务器返回的内容为\n%s",lr_eval_string("{result}"));
	//lr_output_message(lr_eval_string("{response1}"));
	return 0;
}
