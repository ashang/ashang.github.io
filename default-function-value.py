import sys

#If run with no parameters, it appears to have the expected and desired behaviour.
# Give it a parameter, and the line that appends a question will cause *all* instances to have the same question added.

# the default value for the `question` parameter is evaluated at compile time to be an instance of an empty list.
#All instances then refer to this same empty list, so when one gets something appended, they all appear to get it.
#The solution is of course to have it default to `None` and then construct a list when required.

# Even when the default parameter is a function, it is still evaluated only the once, so its return value becomes a constant default value. 
# <a href="http://www.python.org/doc/ref/function.html">Python Language Reference: Section 7.5 Function definitions.

class Group:

    #def __init__(self, name, desc='', questions=[]):
    def __init__(self, name, desc='', questions=[]):
        self.name = name
        self.desc = desc
        #self.questions = questions
        self.questions = questions

    def __repr__(self):
        return'''Group:
        Name:        %s
        Description: %s
        Questions:   %s
        ''' % (self.name, self.desc, ', '.join(self.questions))

def test():
    g1 = Group('foo')
    g2 = Group('baz', 'a really bazzy group')
    g3 = Group('bar', 'some barry groups', ['first q', 'secundo', 'tri'])

    g4 = Group('vroom')

    if len(sys.argv) > 1:
        g4.questions.append('This is not a question')

    print(g1)
    print(g2)
    print(g3)
    print(g4)

if __name__ == '__main__':
    test()
