#include "pipex.h"
char	*get_path(char **s)
{
	int	i;
	char *str = NULL;

	i = 0;
	while(s[i])
	{
		if(ft_strstr(s[i], "PATH="))
			{
				str = ft_strdup(ft_strstr(s[i], "PATH="));
				break;
			}
		i++;
	}
	return str;
}
int main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	char *path;
	char **split_path;

	// if(ac != 5)
	// 	return 0;
	path = get_path(env);
	split_path = ft_split(path, ':');
	// printf("%s\n", split_path[0]);
	while (*split_path)
	{
		if(access("cat", F_OK))
		{
			
			printf("%s\n", *split_path);
			break;
		}
		split_path++;
	}
	
	//fork
	//pipe
	//wait()
	//waitpid()*
	//wexitstatus()*
	// fork();
	// int idmain = getpid();
	// printf("%d\n", idmain);
	// int id = fork();
	// printf("id ---> %d\n", id);
	// if(id == 0)
	// {
	// 	// fork();
	// 	printf("child process\n");
	// }
	// if(id > 0)
	// {
	// 	// fork();
	// 	printf("prnt process\n");
	// }
	
	// printf("hello world\n");
}