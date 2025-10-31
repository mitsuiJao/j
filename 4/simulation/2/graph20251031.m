% 22126 So Nishiyama

t = 0:0.01:2*pi;
x1 = sin(t);
x2 = cos(t);
clf;
plot(t', [x1', x2']);

A = gca; 

title('Graph with MATLAB');
xlabel('t [sec]', 'Position', [3.8, -0.1, 0]);
ylabel('sin(t), cos(t)');

L = A.Children; 
L(1).LineStyle = '--';
L(2).LineStyle = ':';

A.Title.FontSize = 18;
A.XLabel.FontSize = 16;
A.XLabel.FontAngle = 'italic';

A.YLabel.FontSize = 16;

A.XAxisLocation = 'origin';
box off;
grid on;