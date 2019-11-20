/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 13:46:51 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 11:11:44 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *fi, const char *se, size_t len);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
size_t			ft_strlcat(char *dest, const char *src, size_t count);
int				ft_atoi(const char *nptr);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strrev(char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
size_t			ft_strnlen(const char *str, size_t maxlen);
int				ft_lstsize(t_list *lst);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_itoa_u_base(unsigned int n, char *base);
char			*ft_itoa_ll_base(long long n, char *base);
char			*ft_itoa_base(int n, char *base);
int				ft_char_in_string(char c, char *str);
void			ft_strdel(char **ptr);
char			*ft_strfjoin(char *s1, char *s2, int free);
void			ft_putstr(const char *str);
void			ft_putchar(char c);
char			*ft_strrev(char *str);

#endif
