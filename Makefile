targets := calendar.out
objs	:= main.o appt.o calendar.o day.o dayOfWeek.o time.o weeklyAppt.o

CC	:= g++
CFLAGS	:= -Wall
CFLAGS	+= -g

# Enable verbose output if debugging
ifneq ($(V), 1) 
Q = @
endif

all: $(targets)

calendar.out: $(objs) 
	@echo "G++   $@"
	$(Q) $(CC) $(CFLAGS) -o $@ $^ 

%.o: %.cpp 
	@echo "G++   $@"
	$(Q) $(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "CLEAN"
	$(Q) rm -f $(objs) $(targets)
