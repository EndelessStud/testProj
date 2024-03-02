# testProj

#run docker file with command:
sudo docker build -t container_name .
sudo docker run -p 8884:8884 -p 5432:5432 --network=host container_name
#after initialization container at local machine console:
cd TestProject/src
cmake .
sudo make install
#after install service on local machine you can run TestProj as publisher at mosquitto server
#Example:
TestProject pub google.com
#at Docker service you can see " Add The Netherlands in database "
#its mean that json that sended google.com contain host locale country that added in database
