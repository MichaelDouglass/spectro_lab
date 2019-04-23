%% Attach and Say Hello to Photon

clc; clear; close all; instrreset;

ardy = serial('COM10','BaudRate',115200);
fopen(ardy);
fscanf(ardy);

fprintf(ardy, '*IDN?');
fscanf(ardy)
pause(5)

%% Make some Measurements of solvent

range = 10;
bit_chain_water = zeros(1, range);
count = 1;
N = 10;

query(ardy, ":STP:SET 1")

for i = 1:range
    query(ardy, ":STP:MOV 5")
    z_meas = zeros(1, N);
    for j = 1:N
        z = query(ardy, ':MEA?');
        z_meas(j) = str2double(z);
        pause(1)
    end
    z_avg = mean(z_meas);
    bit_chain_water(count) = z_avg;
    count = count + 1;
    pause(1)
end
fprintf('First Sample Collected\n')

%% Move to the start position
query(ardy, ":STP:SET 0")
for i = 1:range
    query(ardy, "STP:MOV 5")
    pause(1)
end
query(ardy, "STP:SET 1")
fprintf("Back to start\n")

%% Measure the solution

bit_chain_soln = zeros(1, range);
count = 1;
N = 10;
for i = 1:range
    query(ardy, ":STP:MOV 5")
    z_meas = zeros(1, N);
    for j = 1:N
        z = query(ardy, ':MEA?');
        z_meas(j) = str2double(z);
        pause(1)
    end
    z_avg = mean(z_meas);
    bit_chain_soln(count) = z_avg;
    count = count + 1;
    pause(1)
end
fprintf("Second Sample Collected\n")

%% Close our Ardy
fclose(ardy);
delete(ardy);
clear ardy

%% Plot our data

wavelength = 700:-33:400;

volts_water = bit_chain_water/1023 * 5;
figure()
plot(wavelength, volts_water)

volts_soln = bit_chain_soln/1023 * 5;
figure()
plot(wavelength, volts_soln)

volts_spectra = volts_soln - volts_water;
figure()
plot(wavelength, volts_spectra)