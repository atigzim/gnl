#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
#include <stddef.h>  // for NULL

char *ft_strcat(char *dest, const char *src) {
    
    char *dest_ptr = dest;
    while (*dest_ptr != '\0') {
        dest_ptr++;
    }

    while (*src != '\0') {
        *dest_ptr = *src;
        dest_ptr++;
        src++;
    }
    *dest_ptr = '\0';
    return dest;
}


int line(char *buffer , int by)
{
	int	i;

	i = by -1;
	//printf("%d\n",i);
	while (i >= 0)
	{
		if (buffer[i] == '\n')
			return (-1);
		i--;
	}
	return(0);
}

char	*get_line(int 	fd)
{
	char	*buffer;
	int		bytes;
	int 	BUFFER_SIZE;
	int		i;
	static char    *str;

	i = 0;
	BUFFER_SIZE = 3;
	//str = malloc(BUFFER_SIZE + 1);
	//if (!str)
	//	return (NULL);
	buffer = malloc( BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (i != -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
        i = line(buffer, bytes);
		str = ft_strjoin(str,buffer);
		//printf("%d\n",i);
	}
	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	//printf("%d",i);
	return(str);
}
int main()
{
	int fd = open("example.txt",O_RDONLY);
	if(fd == -1)
		return (0);
	printf("%s",get_line(fd));
	close(fd);
}
