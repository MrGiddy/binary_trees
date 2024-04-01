class Node():
	def __init__(self, val, left=None, right=None):
		self.val = val
		self.left = None
		self.right = None

a = Node('a')
b = Node('b')
c = Node('c')
d = Node('d')
e = Node('e')
f = Node('f')
a.left = b
a.right = c
b.left = d
b.right = e
c.right = f


		#      a
		#     / \
		#    b    c 
		#   / \   |
		#  d   e  f


# Depth first traversal - Iterative
def depth_first_traversal(root):
	if root is None:
		return []

	stack = [ root ]
	result = []
	while len(stack) > 0:
		current = stack.pop()
		result.append(current.val)

		if (current.right):
			stack.append(current.right)   
		if (current.left):
			stack.append(current.left)
		
	return result

print("Iterative depth first traversal: ")
result = depth_first_traversal(a)
print(result)
result = depth_first_traversal(None)
print(result)

# Recursive depth first traversal
def depth_first_recursion(root):
	if root is None:
		return []

	left_values = depth_first_recursion(root.left)
	right_values = depth_first_recursion(root.right)
	result = [root.val]
	result.extend(left_values)
	result.extend(right_values)
	return result

print("Recursive depth first traversal: ")
result = depth_first_recursion(a)
print(result)
result = depth_first_recursion(None)
print(result)


# Breadth first traversal
def breadth_first_traversal(root):
	if root is None:
		return []
	
	queue = [ root ]
	values = []
	
	while len(queue) > 0:
		current = queue.pop(0)
		values.append(current.val)
		
		if current.left:
			queue.append(current.left)
		if current.right:
			queue.append(current.right)

	return values

print("Breadth first traversal: ")
values = breadth_first_traversal(a)
print(values)
values = breadth_first_traversal(None)
print(values)


# Tree includes problem
	# Breadth-first traversal
def tree_includes_breath_first(root, target):
	if root is None:
		return False

	queue = [ root ]
	while len(queue) > 0:
		current = queue.pop(0)
		if current.val == target:
			return True

		if current.left:
			queue.append(current.left)
		if current.right:
			queue.append(current.right)
	
	return False

print("Tree includes problem, iterative breadth first traversal: ")
result = tree_includes_breath_first(a, 'e')
print(result)
result = tree_includes_breath_first(a, None)
print(result)


def tree_includes_recursive(root, target):
	if root is None:
		return False
	
	if root.val == target:
		return True

	left_side = tree_includes_recursive(root.left, target)
	right_side = tree_includes_recursive(root.right, target)

	return left_side or right_side

print("Tree includes problem, recursive depth first solution")
result = tree_includes_recursive(a, 'e')
print(result)
result = tree_includes_breath_first(a, None)
print(result)


a = Node(1)
b = Node(2)
c = Node(3)
d = Node(4)
e = Node(5)
f = Node(6)
a.left = b
a.right = c
b.left = d
b.right = e
c.right = f

# Tree sum
def tree_sum_recursive(root):
	if root is None:
		return 0
	
	return root.val + tree_sum_recursive(root.left) + tree_sum_recursive(root.right)

print("Tree sum recursive solution: ")
result = tree_sum_recursive(a)
print(result)

# Tree sum - Iterative
def tree_sum_iterative(root):
	if root is None:
		return 0
	
	queue = [ root ]
	total_sum = 0

	while len(queue) > 0:
		current = queue.pop(0)
		total_sum += current.val

		if current.left:
			queue.append(current.left)
		if current.right:
			queue.append(current.right)

	return total_sum

print("Tree sum iterative solution: ")
result = tree_sum_iterative(a)
print(result)

from math import inf

# Tree Min Value recursive
def tree_min_value_recursive(root):
	if root is None:
		return inf
	
	left_min = tree_min_value_recursive(root.left)
	right_min = tree_min_value_recursive(root.right)
	return min(root.val, left_min, right_min)

print("Tree minimum value recursive")
result = tree_min_value_recursive(a)
print(result)


# Tree Min Value Iterative breadth first using queue
def tree_min_value_breadth_first_queue(root):
	if root is None:
		return []
	
	min_value = inf
	
	queue = [ root ]

	while len(queue) > 0:
		current = queue.pop(0)
		if current.val < min_value:
			min_value = current.val

		if current.left:
			queue.append(current.left)
		if current.right:
			queue.append(current.right)
	
	return min_value

print("Tree min value breadth first using queue:")
result = tree_min_value_breadth_first_queue(a)
print(result)

# Tree min value depth first using stack
def tree_min_value_depth_first_stack(root):
	if root is None:
		return inf
	
	stack = [ root ]
	min_value = inf

	while len(stack) > 0:
		current = stack.pop(0)
		if current.val < min_value:
			min_value = current.val

		if (current.right):
			stack.append(current.right)   
		if (current.left):
			stack.append(current.left)

	return min_value

print("Tree min value depth first using stack:")
result = tree_min_value_depth_first_stack(a)
print(result)

# Tree min value recursive - depth first traversal
def tree_min_value_recursive(root):
	if root is None:
		return inf
	
	left_min = tree_min_value_recursive(root.left)
	right_min = tree_min_value_recursive(root.right)
	return min(root.val, left_min, right_min)

print("Tree min value recursive solution - depth first")
result = tree_min_value_recursive(a)
print(result)


# Max root to leaf path sum
def max_root_to_leaf_path_sum(root):
	if root is None:
		return -inf

	if root.left is None and root.right is None:
		return root.val
	
	left_max = max_root_to_leaf_path_sum(root.left)
	right_max = max_root_to_leaf_path_sum(root.right)
	max_child_path_sum = max(left_max, right_max)

	return root.val + max_child_path_sum

print("Max root to leaf path sum:")
result = max_root_to_leaf_path_sum(a)
print(result)
