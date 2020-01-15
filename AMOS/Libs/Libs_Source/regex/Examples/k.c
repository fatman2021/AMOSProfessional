
#include <proto/regex.h>
#include <proto/exec.h>
#include <stdio.h>
#include <string.h>

#define NS 10

struct Library *RegexBase;

void main(int argc,char **argv)
{
	regmatch_t 	subs[NS];
	ULONG 		eopts=0;
	int 		i, len;
	regoff_t 	startoff = 0;
	regoff_t 	endoff = 0;
	char errbuf[256];
	regex_t	re;
	int copts = REG_EXTENDED;
	int err;

	if (argc!=3)
	{
		printf("Usage: k <regex> <string>\n");
		return;
	}

	RegexBase = OpenLibrary("regex.library",0);
	if (!RegexBase)
	{
		printf("no RegexBase\n");
		return;
	}

	err = regcomp(&re,argv[1],copts);
	if (err)
	{
		regerror(err,&re,errbuf,sizeof(errbuf));
		printf("regcomp: %s\n",errbuf);
		CloseLibrary(RegexBase);
		return;
	}

	subs[0].rm_so = startoff;
	subs[0].rm_eo = strlen(argv[2]) - endoff;

	err = regexec(&re,argv[2],(size_t)NS,subs,eopts);
	if (err)
	{
		regerror(err,&re,errbuf,sizeof(errbuf));
		printf("regexec: %s\n",errbuf);
		regfree(&re);
		CloseLibrary(RegexBase);
		return;
	}

	len = (int)(subs[0].rm_eo - subs[0].rm_so);
	if (subs[0].rm_so != -1)
	{
		printf("len:%d   ",len);
		if (len != 0)
				printf("<match `%.*s'\n", (int)len,
					argv[2] + subs[0].rm_so);
			else
				printf(">match `'@%.1s\n",
					argv[2] + subs[0].rm_so);
	}
	for (i = 1; i < NS; i++)
	{
		if (subs[i].rm_so != -1)
			printf("(%ld) %ld `%.*s'\n",i,(int)(subs[i].rm_eo - subs[i].rm_so),argv[2] + subs[i].rm_so);
	}

	regfree(&re);
	CloseLibrary(RegexBase);
}
