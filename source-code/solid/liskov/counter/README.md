# Counter


Implementations of a class that computes a histogram of integer values between
a given minimum and maximum value.  A relative counter is also defined that
returns the normalized values of the histogram.  The constructor of this class
takes an absolute counter as an argument.  The relative counter is intended as
a transformation, so it doesn't define a method to add values to the histogram,
as the absolute counter does.

Several implementations of the absolute and relative counters.


## What is it?

1. `base_case/`: simple implementation of the absolute and relative counters as
   independent classes with quite some code duplication.
1. `violation`: an implementation that derives the relative counter from the
   absolute counter, violating the Liskov substitution principle.
1. `templates`: an implementation that uses templates to avoid code
   duplication and doesn't violate the Liskov substitution principle.
