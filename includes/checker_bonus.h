/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:27:34 by acherifi          #+#    #+#             */
/*   Updated: 2026/01/10 10:42:42 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h> 
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct s_split_data
{
	size_t	count;
	size_t	len;
	size_t	word_len;
	size_t	i;
	size_t	j;
	size_t	in_word;
}	t_split;

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	int				position;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

// Utils Functions

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2, ssize_t len);
ssize_t	ft_strlen(char const *s);
int		ft_atoi(const char *nptr);
int		my_isdigit(char *str);
int		ft_numlen(int nb);
t_stack	*lst_create(int value);
void	lst_addback(t_stack **lst, t_stack *new);
int		ft_isspace(char *str);
char	**create_array(char **av, int ac, char **array);
int		create_stack(t_stack **lst, char **array);
int		process_argument(t_stack **lst, char *array);
char	*check_zero(char *str);
int		check_duplicates(char **array);
void	free_stack(t_stack **lst);
void	free_array(char **array);
void	assign_indexes(t_stack *lst);
void	assign_positions(t_stack *lst);
void	push_stack_b(t_stack **lst, t_stack **b);
int		lst_size(t_stack *lst);
void	parse_stack_a(t_stack **a, t_stack **b);
int		is_sorted(t_stack *a);

// Get next line Functions

char	*ft_substr(char const *s, ssize_t start, ssize_t len);
ssize_t	ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*my_strjoin(char const *s1, char const *s2, ssize_t len);

// Rules Functions

void	pa(t_stack **a, t_stack **b, int is_valid);
void	pb(t_stack **b, t_stack **a, int is_valid);

void	sa(t_stack **a, int is_valid);
void	sb(t_stack **b, int is_valid);
void	ss(t_stack **a, t_stack **b, int is_valid);

void	ra(t_stack **a, int is_valid);
void	rb(t_stack **b, int is_valid);
void	rr(t_stack **a, t_stack **b, int is_valid);

void	rra(t_stack **a, int is_valid);
void	rrb(t_stack **b, int is_valid);
void	rrr(t_stack **a, t_stack **b, int is_valid);

#endif
