################################
##Generated with a lot of love##
##    with   EasyPython       ##
##Web site: easycoding.tn     ##
################################

variable_A = None
variable_B = None
variable_C = None

def upRange(start, stop, step):
  while start <= stop:
    yield start
    start += abs(step)

def downRange(start, stop, step):
  while start >= stop:
    yield start
    start -= abs(step)


variable_A = 'Hello'
variable_B = 3
print('abc')
print('123')
for variable_C in (float(variable_B) <= -1) and upRange(float(variable_B), -1, -1) or downRange(float(variable_B), -1, -1):
  print(variable_A)
  print(variable_C)
  print(variable_C * variable_C)
