int main()
{
	char *path = "Files";
	DIR *directory = opendir(path);
	assert(directory != NULL);
	struct dirent *directoryEntry;
	
	char fileNames[50][256] = {{0}};
	char temporary[256] = {0};
	int fileIndex = 0;
	while((directoryEntry = readdir(directory)) != NULL)
	{	
		if(directoryEntry->d_name[0] != '.')
		{
			//printf("%s\n",directoryEntry->d_name);
			strcpy(fileNames[fileIndex], directoryEntry->d_name);
			fileIndex++;
		}
	}
	for(int k = 0; k < fileIndex; k++)
	{
		for(int j = k + 1; j < fileIndex; j++)
		{
			if(strcasecmp(fileNames[k], fileNames[j]) > 0)
			{
				strcpy(temporary, fileNames[k]);
				strcpy(fileNames[k], fileNames[j]);
				strcpy(fileNames[j], temporary);
				memset(temporary,0,256);	
			}	
		}
	}
	
	for(int i = 0 ; i < fileIndex; i++)
	{
		printf("%s\n", fileNames[i]);
	}
	closedir(directory);
	return 0;
}
