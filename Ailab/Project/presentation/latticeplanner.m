clear;clc;close all
%%% 경계조건
% 횡방향 곡선식을 3차곡선으로 구성
% sf는 곡선의 길이
% e_yaw(sf) = 0
% l(sf) = y_offset
% y_offset0 = 0
% e_yaw(0) = heading_angle - way_direction
% 결정줘야하는 것 -> 목표 yoffset, 곡선 길이
%%% 최대 곡률이 한계곡률보다 작을 떄까지 곡선 길이 늘림

sf = 5.5;
dtheta = 0.0; % rad
y_offset = 1.5;
% max_kappa = 0.173;
% max_kappa = 1/2.75;
max_lateral_acc = 2.94;
max_kappa = 1/3;
length_ratio = 1.05;
road_width = 2.75;

sf2 = 4;
y_offset2=road_width;
dtheta2 = -0.05;
sf1 = 3;
y_offset1 = road_width/2;
dtheta1 = 0.0;
[s1,y1,dlds1,ddlds1,theta1,kappa1] = getCurve(sf1,dtheta1,y_offset1);
velocity1 = zeros([1,length(kappa1)]);

% % velocity1 = min( sqrt(max_lateral_acc./kappa1),20);


while(abs(kappa1(1)) > max_kappa)
    sf1 = length_ratio* sf1; 
    [s1,y1,dlds1,ddlds1,theta1,kappa1] = getCurve(sf1,dtheta1,y_offset1);
end

[s2,y2,dlds2,ddlds2,theta2,kappa2] = getCurve(sf2,dtheta2,y_offset2);
while(abs(kappa2(1)) > max_kappa)
    sf2 = length_ratio* sf2; 
    [s2,y2,dlds2,ddlds2,theta2,kappa2] = getCurve(sf2,dtheta2,y_offset2);
end

velocity2 = sqrt(max_lateral_acc./kappa2);


fontsize = 14;


for i=1:length(kappa1)
    if(kappa1(i) ~= 0)
        velocity1(i) = min( sqrt(max_lateral_acc/abs(kappa1(i))),20);
    elseif(kappa1(i) ==0) 
        velocity1(i) = 20;
    end
end
for i=1:length(kappa2)
    if(kappa2(i) ~= 0)
        velocity2(i) = min( sqrt(max_lateral_acc/abs(kappa2(i))),20);
    elseif(kappa1(i) ==0) 
        velocity2(i) = 20;
    end
end


plot(s2,y2, LineWidth=2);
hold on
theta1 = tan(dlds1);
dx1 = dlds1.*theta1;
x=zeros(length(dx1));
for i=1:length(dx1)
    x(i) = sum(dx1(1:i));
end
plot(s1, y1, LineWidth=2);
xlim([ min(s2)-0.1 max(s2)+0.1])
ylim([ min(y2)-0.1 max(s2)+0.1])
xlabel('s (m)')
ylabel('y (m)')
title("Lateral Offset = 2.75(m)")
grid on
set(gca, 'FontSize', fontsize);
% 


figure

plot(s2 ,kappa2, LineWidth = 2);
hold on
plot(s2, theta2,LineWidth=2);
grid on
xlim([ min(s2) max(s2)])
ylim([ min(theta2)-0.3 max(theta2)+0.3])
xlabel('s (m)')
ylabel('(rad)')
title("Lateral Offset = 2.75(m)")
legend("Curvature","Heading Angle Error", fontsize=fontsize)
set(gca, 'FontSize', fontsize);

figure
theta1 = tan(dlds1);
dx1 = dlds1.*theta1;
x=zeros(length(dx1));
for i=1:length(dx1)
    x(i) = sum(dx1(1:i));
end
plot(s1, y1, LineWidth=2);
xlim([ min(s1)-0.1 max(s1)+0.1])
ylim([ min(y1)-0.1 max(s1)+0.1])
xlabel('s (m)')
ylabel('y (m)')
title("Lateral Offset = 1.375 (m)")
set(gca, 'FontSize', fontsize);
grid on

figure
plot(s1 ,kappa1, LineWidth=2);
hold on
plot(s1, theta1,LineWidth=2);
grid on
xlim([ min(s1) max(s1)])
ylim([ min(theta1)-0.3 max(theta1)+0.3])
xlabel('s (m)')
ylabel('(rad)')
title("Lateral Offset = 1.375 (m)")
legend("Curvature","Heading Angle Error", fontsize=fontsize)
set(gca, 'FontSize', fontsize);

figure
plot(s2,velocity2,LineWidth=2)
hold on
plot(s1,velocity1,LineWidth=2)
grid on
xlabel('s (m)')
ylabel('velocity (m/s)')
title('Velocity Curve Length')
legend("Lateral Offset = 2.75","Lateral Offset = 1.375", fontsize = fontsize)
set(gca, 'FontSize', fontsize);

