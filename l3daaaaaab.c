#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (strdup(""));
	if (s1 == NULL && s2)
		return (strdup(s2));
	else if (s2 == NULL && s1)
		return (strdup(s1));
	p = (char *)malloc(sizeof(char) * strlen(s1) + strlen(s2) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	return (p);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= strlen(s))
		return (strdup(""));
	i = 0;
	if (len > strlen(s) - start)
		len = strlen(s) - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
int	chlin( char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
int line (char *buffer, int by)
{
    int i ;

    i = 0;
    while(by >= i)
    {
        if( buffer[i] == '\0' || buffer[i] == '\n')
            return (0);
        i++;
	printf("%d\n",i);

    }
	printf("hh%d\n",i);
    return (i);
}

char	*get_line(int 	fd)
{
    int by = 0;
    int i = 1;
	int k = 0;
    char *buffer;
    int 	BUFFER_SIZE;
    char    *str = NULL;
	char    *str1;
	static char    *st;
    BUFFER_SIZE = 3;
    buffer = malloc(BUFFER_SIZE + 1);
	if(st == 0)
	{ 
    	while (i != 0)
    	{
        	by = read(fd, buffer, BUFFER_SIZE);
			printf("...%d  %s...",by,buffer);
			buffer[by] = '\0';
			//printf("%s\n",buffer);
			str = ft_strjoin(str,buffer);
			by--;
			i = line(str,by);
			printf("i = %d\n",i);
		}
		//printf("111 == %s 111", str);
		i = chlin(str);
		if (str[i])
			i++;
		str1 = malloc(i);
		str1 = ft_strjoin(str1,str);
		//printf("%s\n",str);	
		str1 = ft_substr(str , 0, i);
		//printf("%s\n",str1);
		//printf("%s\n",str);
		
		st = ft_substr(str, i-1,strlen(str) -i);
		//printf("%s\n",st);
		// 	st[k++] = str[i++];
		// st[k] = '\0';
		//printf("st = %s\n",st);
		//printf("%s\n",str);
	}
	 else 
	{
		str = ft_strjoin(st,str);
		//printf("%s",str);
		while (i != 0)
    	{
			printf("12\n");
        	by = read(fd, buffer, BUFFER_SIZE);
			buffer[by] = '\0';
			//printf("%s\n",buffer);
			printf("%d\n",by);
			str = ft_strjoin(str,buffer);
			by--;
			i = line(str,by);
		}
		i = chlin(str);
		if (str[i])
			i++;
		str1 = malloc(i);
		str1 = ft_strjoin(str1,str);
		//printf("%s\n",str);	
		str1 = ft_substr(str , 0, i);
		//printf("%s\n",str1);
		//printf("%s\n",str);
		
		st = ft_substr(str, i-1,strlen(str) -i);
		//printf("%s\n",st);
		// 	st[k++] = str[i++];
		// st[k] = '\0';
		//printf("st = %s\n",st);
	}
    return(str1);
}

int main()
{
	int fd = open("abdo.txt",O_RDONLY);
	if(fd == -1)
		return (0);
	printf("%s",get_line(fd));
	printf("%s",get_line(fd));
	//printf("%s\n",get_line(fd));
	close(fd);
}