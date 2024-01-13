%% 1
clc
clear
grid_length=61;
start_pos=10;
curr_pos=start_pos;
angles=linspace(0,2*pi,grid_length);
radius=20;
CenterX=0;
CenterY=0;
x=radius*cos(angles)+CenterX;
y=radius*sin(angles)+CenterY;
% Set up figure properties:
% Enlarge figure to full screen.
set(gcf, 'Units', 'Normalized', 'OuterPosition', [0 0 1 1]);
% Get rid of tool bar and pulldown menus that are along top of figure.
set(gcf, 'Toolbar', 'none', 'Menu', 'none');
plot(x,y,'-o','MarkerIndices',1:1:length(y));
%axis tight
hold on;
plot(CenterX,CenterY,'k+','LineWidth',3,'MarkerSize',14);
radius2=25;
grid on;
xlim([-27.5,27.5]);
ylim([-27.5,27.5]);
xlabel('X','FontSize',14);
ylabel('Y','FontSize',14);
xnew=radius2*cos(angles)+CenterX;
ynew=radius2*sin(angles)+CenterY;
plot(xnew,ynew,"Color","none");
for i=1:length(ynew)-1
    text(xnew(i),ynew(i),strcat(num2str(i)),"Color","k")
end
x2=start_pos;
hops=0;
plot(x(x2),y(x2),".","MarkerSize",20)
r_l_store=[];curr_pos_store=[];
while curr_pos~=60
    r_l=randi(10);
    if (0<r_l)&&(r_l<4)
        curr_pos=curr_pos-1;
    elseif r_l==4
        curr_pos=curr_pos+0;
    else
        curr_pos=curr_pos+1;
    end
    if curr_pos==0
        curr_pos=60;
    end
    curr_pos_store=[curr_pos_store curr_pos];
    r_l_store=[r_l_store r_l];
    x2=curr_pos;
    plot(x(x2),y(x2),".","MarkerSize",20)
    if curr_pos==60
    text(5,0,strcat("No. of Hops: ",num2str(hops)),"Color","k")
    text(-15,0,strcat("Starting Pos: ",num2str(start_pos)),"Color","k")
    end
    %pause(.05)
    hops=hops+1;
    f=getframe;
end
hold off
movie(f)