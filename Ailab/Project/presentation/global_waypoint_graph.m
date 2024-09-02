% next.txt와 pose.txt 파일 경로 설정
nextFile = '/Users/youngki/study/Ailab/Project/presentation/next_interpolation.txt';
poseFile = '/Users/youngki/study/Ailab/Project/presentation/pose_interpolation.txt';

% next.txt와 pose.txt 파일에서 좌표 데이터를 읽어옵니다.
nextData = readmatrix(nextFile);
poseData = readmatrix(poseFile);

% 데이터 크기 확인 (행 개수가 같아야 함)
if size(nextData, 1) ~= size(poseData, 1)
    error('next.txt와 pose.txt 파일의 행 개수가 다릅니다.');
end

% 각 행마다 두 점 간의 거리를 계산합니다.
numPoints = size(nextData, 1); % 점의 개수
distances = zeros(numPoints, 1); % 거리 배열 초기화

for i = 1:numPoints
    % 두 점 간의 유클리드 거리 계산
    distances(i) = sqrt((nextData(i, 1) - poseData(i, 1))^2 + (nextData(i, 2) - poseData(i, 2))^2);
end
index = 1:length(distances);
plot(index, distances);
grid on;
ylim([-0.3,3.3]);
xlabel("index");
ylabel("distance (m)")
title("distance between EgoPos and NextWaypoint")

% 결과 출력
disp('각 행마다 두 점 간의 거리:');
disp(distances);

% 
% % 필요에 따라 거리를 파일로 저장할 수 있습니다.
% outputFile = 'distances.txt';
% dlmwrite(outputFile, distances, 'delimiter', '\t');