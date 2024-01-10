/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calizade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:11:14 by calizade          #+#    #+#             */
/*   Updated: 2023/11/23 15:29:07 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// STRING MANIPULATION / MANDATORY
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

size_t				ft_strlen(const char *s);

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

int					ft_toupper(int c);
int					ft_tolower(int c);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strnstr(const char *big, const char *little,
						size_t len);

int					ft_atoi(const char *nptr);

void				*ft_calloc(size_t nmemb, size_t size);

char				*ft_strdup(const char *s);

char				*ft_itoa(long n);

char				*ft_substr(const char *s, unsigned int start, size_t len);

char				*ft_strjoin(const char *s1, const char *s2);

char				*ft_strtrim(const char *s1, const char *set);

char				**ft_split(char const *s, char c);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// LIST / BONUS
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);

void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// PERSO
int					ft_isspace(int c);

void				ft_strinsrtend(char **s1, const char *s2);
void				ft_strinsrtstart(char **s1, const char *s2);
void				ft_strninsrtend(char **s1, const char *s2, unsigned int n);
void				ft_strninsrtstart(char **s1, const char *s2,
						unsigned int n);

void				charset_to_charmap(char *charset, int charmap[256]);
void				base_to_charmap(char *base, int charmap[256]);

int					get_ndigits(long n);
int					get_nchar(long n);
int					get_ndigits_base(long n, unsigned int baselen);
int					get_nchar_base(long n, unsigned int baselen);

int					get_undigits(unsigned long n);
int					get_unchar(unsigned long n);
int					get_undigits_base(unsigned long n, unsigned long baselen);
int					get_unchar_base(unsigned long n, unsigned long baselen);

long				ft_atoi_base(const char *nptr, char *base);
char				*ft_itoa_base(long nb, char *base);
char				*ft_uitoa_base(unsigned long nb, char *base);
char				*ft_to_base(const char *nptr, char *base_from,
						char *base_to);

#endif
