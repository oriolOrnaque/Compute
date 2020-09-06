

class Node:
	def compute(self, input):
		pass


class Sum(Node):
	def __init__(self, term):
		self.term = term

	def compute(self, input):
		return self.term + input

	def __str__(self):
		return "+" + str(self.term)


class Multiply(Node):
	def __init__(self, factor):
		self.factor = factor

	def compute(self, input):
		return self.factor * input

	def __str__(self):
		return "*" + str(self.factor)


class Divide(Node):
	def __init__(self, factor):
		if factor == 0:
			raise ValueError("Divisor is 0")
		self.factor = factor

	def compute(self, input):
		return input / self.factor

	def __str__(self):
		return "/" + str(self.factor)


class ChangeSign(Node):
	def compute(self, input):
		return input * (-1)

	def __str__(self):
		return "+/-"


class AppendRight(Node):
	def __init__(self, num):
		if num >= 10:
			raise ValueError("Num greater or equal than 9")
		elif num < 0:
			raise ValueError("Num less than 0")
		self.num = num

	def compute(self, input):
		return (input * 10) + self.num

	def __str__(self):
		return str(self.num)


class PopRight(Node):
	def compute(self, input):
		return input // 10

	def __str__(self):
		return "<<"


class Solution:
	def __init__(self, path):
		self.solution = path

	def __len__(self):
		return len(self.solution)

	def __getitem__(self, index):
		return self.solution[index]

	def __str__(self):
		qwe = ""
		for i in range(len(self.solution)):
			qwe += self.solution[i].__str__()
			if i != len(self.solution) - 1:
				qwe += " -> "
		return qwe


class Solutions:
	def __init__(self, problem):
		self.problem = problem
		self.solutions = []
		self.min_solution = None
		self.max_solution = None

	def add_solution(self, path):
		solution = Solution(path)
		self.solutions.append(Solution(solution))
		if self.min_solution is None:
			self.min_solution = solution
		else:
			if len(solution) < len(self.min_solution):
				self.min_solution = solution
		if self.max_solution is None:
			self.max_solution = solution
		else:
			if len(solution) > len(self.max_solution):
				self.max_solution = solution

	def get_max_solution(self):
		return self.max_solution

	def get_min_solution(self):
		return self.min_solution

	def __str__(self):
		qwe = self.problem.__str__() + ":\n"
		for i in range(len(self.solutions)):
			qwe += "\t" + self.solutions[i].__str__()
			qwe += "\n"
		return qwe


class Problem:
	def __init__(self, goal, operations, initial, n_movs):
		self.goal = goal
		self.operations = operations
		self.initial = initial
		self.n_movs = n_movs

	def solve(self):
		stack = [(self.initial, [], self.n_movs)]
		solutions = Solutions(self)
		while stack:
			val, path, movs = stack.pop()
			if val == self.goal:
				solutions.add_solution(path)
				continue
			if movs == 0:
				continue
			for operation in self.operations:
				new_path = path.copy()
				new_path.append(operation)
				stack.append((operation.compute(val), new_path, movs-1))
		return solutions

	def __str__(self):
		qwe =  str(self.initial) + " to " + str(self.goal) + " in " + str(self.n_movs) + " actions"
		return qwe


if __name__ == "__main__":
	problem = Problem(-11, [ChangeSign(), Multiply(6), PopRight(), Sum(29)], -103, 1)
	solutions = problem.solve()
	print(solutions)
