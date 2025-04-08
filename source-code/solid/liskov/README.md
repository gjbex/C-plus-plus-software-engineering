# Liskov substitution principle

The Liskov substitution principle is the third principle of the SOLID
principles. It was introduced by Barbara Liskov in 1987. The principle states
that objects of a superclass should be replaceable with objects of its
subclasses without affecting the correctness of the program. 

The principle is based on the idea that a subclass should extend the
functionality of its superclass without changing the behavior of the superclass.


## What is it?

1. `counter`: implementations of a class that computes a histogram of integer
   values between a given minimum and maximum value.  A relative counter is
   also defined that returns the normalized values of the histogram.  The
   constructor of this class takes an absolute counter as an argument.  The
   relative counter is intended as a transformation, so it doesn't define a
   method to add values to the histogram, as the absolute counter does.
