Action()
{
	extern char *strtok(char *string, const char *delimiters);
	char path[] = "c:\\mercury\\lrun\\bin\\wlrun.exe";
	char separators[] =".\\";
	char *token;
	char arr[6][10];
	int i=1;
	
	token = (char*)strtok(path, separators);
	if(!token){
		lr_output_message("No tokens found in string");
		return(-1);
	}else{
		while(token != NULL){
		lr_output_message("%s", token);
		strcpy(arr[i], token);
		
		token = (char *)strtok(NULL, separators);
		i++;

		}

	}


	lr_output_message("val #1: %s", arr[1]);
	lr_output_message("val #2: %s", arr[2]);
	lr_output_message("val #3: %s", arr[3]);
	lr_output_message("val #4: %s", arr[4]);
	lr_output_message("val #5: %s", arr[5]);
	lr_output_message("val #6: %s", arr[6]);

		
	lr_save_string(arr[1],"temp_1");
	lr_save_string(arr[2],"temp_2");
	lr_save_string(arr[3],"temp_3");
	lr_save_string(arr[4],"temp_4");
	lr_save_string(arr[5],"temp_5");
	lr_save_string(arr[6],"temp_6");

	lr_eval_string("{temp_4}");
       
	return 0;
}
