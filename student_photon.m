%% Student Skeleton for EBME 360 Spectro_Lab
%{
Name:
Date:
Favorite Animal (Collectively):

HINT: LOOK AT THE QUESTIONS BEFORE DOING THE LAB SO YOU KIND OF KNOW WHAT
TO PAY ATTENTION TO.
%}

%% Open Up Our Ardunio
ardy = serial('port', 'BaudRate', 115200);
fopen(ardy)
fscanf(ardy)

% After you successfully open your instrument, you can send commands in the
% command window below. It is a good way to test stuff before you write a
% lot of the data acqusition.

%% Send your first message
fprintf(ardy, "Message Here")
% Don't suppress this if you want to see the message
fscanf(ardy)
% Always follow an fprintf with an fscanf for our purposes.

% Show that quirky message to your TA so we can laugh collectively

%% Move the stepper motor
% Hint: It might be easier to do this in the command window as you align
% the rainbow to the path of the photoresistor

% A stepper motor takes... STEPS. The electronics behind the device is very
% cool, and you should be familiar with it, but let's just use the device
% as a black box. Use the SCPI command :STP:MOV N to move a certain number
% of steps. Then, use the SCPI command :STP:SET N to change directions and
% move the same number of steps back.

fprintf(ardy, "")
fscanf(ardy)
pause(2)

% Okay. The easiest way to be clever is to use the query() function. It
% sends a message and receives a response in one fluid motion. In more
% relevant terms, it does an fprintf and an fscanf at THE SAME TIME!!!

query(ardy, "")
pause(2)


%% Collect Baseline Data for Water
%{
So here is a good place for a for loop. You might want to test the step
size of the motor. Do not do :STP:MOV 1 because that's too little. Do not
do :STP:MOV 100 because that's too big. There is a sweet spot step size to
move within 1 and 100 steps. The photoresistor also takes some time to
settle, so you might want to wait a little before you take a measurement,
or take many measurements and average them to create actual data.

I would try to start my measurements just before the red region and end
just after the blue region. This means taking steps through the rainbow of
ROYGBIV

The photoresistor has a potentiometer on it. You are smart and capable.
Adjust that to get a good signal and sensitivity. Maybe play around in the
command window the the :MEA? SCPI command to make some baseline
measurements.

The :MEA? command returns a string. Use the MATLAB function str2num() to
make that into a number.
%}

range = ; %  How many times your for loop cycles
N = ;  % Maybe how many times you average the measurement

% Initial Intensity
baseline_readings = zeros(1, range);  % Initialize an array 

for i = 1:range
    % This for loop is for moving 
    for j = 1:N
        % This for loop is for averaging
        
        
    end
    
end

%% Move the stepper motor back to the position you started at.

% Change the direction
query(ardy, "")

% Move

%% Now take the measurement of the sample

% Final Intensity
sample_readings = zeros(1, range);  % Initialize an array 

for i = 1:range
    % This for loop is for moving 
    for j = 1:N
        % This for loop is for averaging
        
        
    end
    
end

%% Sweet we've collected all the data let's say goodbye to ardy

query(ardy, ":STP:BYE")

fclose(ardy)
delete(ardy)
clear ardy

%% Let's manipulate our data

%{
I am ecstatic that you've made it to this point. What we want to do is take
a look at the absorbance "Fingerprint" and see if that makes sense. If not,
I think that is alright as long as you can answer some of these questions
at the end. Showing understanding but failing in the lab is kind of par for
the course. Things are difficult. The moon may be out of phase. You could
be tired. Who knows? I digress.

We want to set a range of estimated wavelengths to get a COARSE
understanding of our data. Then plot the sample minus the background.
%}

% 650nm is red, and 400nm is blue. These are estimates. Use your already
% tested problem solving skills to change this array around. If you started
% measurements with blue light, this will be different.

wavelengths = 650:{INSERT A STEP SIZE HERE}:400;

% Now plot the baseline data
figure()

% Plot the sample data
figure()

% Plot the sample / baseline data
figure()

%% Okay now comes the questions
%{
When playing around with the photoresistor did voltages rise or fall with
more incident light on the photoresistor?


%}

%{
Based on your answer to the last question, which reading has a higher
absorbance, 1.50 V or 3.00 V?



%}

%{
Beer's Law is A = e C l. You touched on this in class. You also just
psuedo-measured absorbance. If you are characterizing a molecule in
solution, which variable would be the one that you would put on a datasheet
and what are it's units?



%}

%{
A recently discovered molecular toxicity has been shown to cause symptoms
of hallucination and increased stress at blood concentrations of 150mg/mL
in blood. Can you think of a sequence of experiments to use Beer's Law (A =
e C l) to diagnose this disease state?


%}

%{
Think of one application for using spectrophotometry that is not pulse-ox.
Or spinach. Does not have to be BME related. 

%}