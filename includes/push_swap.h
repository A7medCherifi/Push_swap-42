/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:27:44 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/29 18:27:05 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> 
# include <unistd.h>
# include <limits.h>

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
int		is_sorted(t_stack *a);

// Algorithm Functions

void	sort_three_numbers(t_stack **lst);

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

void	count_target(t_stack *a, t_stack **b);
void	sort_push_a(t_stack **a, t_stack **b);
void	last_sort_a(t_stack **a);
int		get_less_move(t_stack *b);

#endif