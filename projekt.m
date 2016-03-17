function varargout = projekt(varargin)
% PROJEKT MATLAB code for projekt.fig
%      PROJEKT, by itself, creates a new PROJEKT or raises the existing
%      singleton*.
%
%      H = PROJEKT returns the handle to a new PROJEKT or the handle to
%      the existing singleton*.
%
%      PROJEKT('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PROJEKT.M with the given input arguments.
%
%      PROJEKT('Property','Value',...) creates a new PROJEKT or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before projekt_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to projekt_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help projekt

% Last Modified by GUIDE v2.5 11-Dec-2015 20:08:41

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @projekt_OpeningFcn, ...
                   'gui_OutputFcn',  @projekt_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before projekt is made visible.
function projekt_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to projekt (see VARARGIN)

% Choose default command line output for projekt
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes projekt wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = projekt_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function wx_Callback(hObject, eventdata, handles)
% hObject    handle to wx (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of wx as text
%        str2double(get(hObject,'String')) returns contents of wx as a double


% --- Executes during object creation, after setting all properties.
function wx_CreateFcn(hObject, eventdata, handles)
% hObject    handle to wx (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function wy_Callback(hObject, eventdata, handles)
% hObject    handle to wy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of wy as text
%        str2double(get(hObject,'String')) returns contents of wy as a double


% --- Executes during object creation, after setting all properties.
function wy_CreateFcn(hObject, eventdata, handles)
% hObject    handle to wy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function nx_Callback(hObject, eventdata, handles)
% hObject    handle to nx (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of nx as text
%        str2double(get(hObject,'String')) returns contents of nx as a double


% --- Executes during object creation, after setting all properties.
function nx_CreateFcn(hObject, eventdata, handles)
% hObject    handle to nx (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function ny_Callback(hObject, eventdata, handles)
% hObject    handle to ny (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of ny as text
%        str2double(get(hObject,'String')) returns contents of ny as a double


% --- Executes during object creation, after setting all properties.
function ny_CreateFcn(hObject, eventdata, handles)
% hObject    handle to ny (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function dT_Callback(hObject, eventdata, handles)
% hObject    handle to dT (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of dT as text
%        str2double(get(hObject,'String')) returns contents of dT as a double


% --- Executes during object creation, after setting all properties.
function dT_CreateFcn(hObject, eventdata, handles)
% hObject    handle to dT (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function N_Callback(hObject, eventdata, handles)
% hObject    handle to N (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of N as text
%        str2double(get(hObject,'String')) returns contents of N as a double


% --- Executes during object creation, after setting all properties.
function N_CreateFcn(hObject, eventdata, handles)
% hObject    handle to N (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in load.
function load_Callback(hObject, eventdata, handles)
global dx dy N nx ny folder;
wx=str2double(get(handles.wx,'String'));
wy=str2double(get(handles.wy,'String'));
dT=str2double(get(handles.dT,'String'));
N=round(str2num(get(handles.N,'String')));
nx=round(str2num(get(handles.nx,'String')));
ny=round(str2num(get(handles.ny,'String')));
dx=20*wx^0.5/nx/0.0364;
dy=20*wy^0.5/ny/0.0364;   
fp3=fopen(strcat(folder,'labp_data.txt'),'w');
fprintf(fp3,'%f\n%f\n%f\n%d\n%d\n%d',wx,wy,dT,nx,ny,N);
fclose(fp3);
guidata(hObject, handles);
% hObject    handle to load (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in run.
function run_Callback(hObject, eventdata, handles)
system('labp_2.out &');
guidata(hObject, handles);
% hObject    handle to run (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in set_N.
function set_N_Callback(hObject, eventdata, handles)
% hObject    handle to set_N (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns set_N contents as cell array
%        contents{get(hObject,'Value')} returns selected item from set_N


% --- Executes during object creation, after setting all properties.
function set_N_CreateFcn(hObject, eventdata, handles)
% hObject    handle to set_N (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in load_functions.
function load_functions_Callback(hObject, eventdata, handles)
global nx ny dx dy X Y Z2 folder;
fp=fopen(strcat(folder,'labp_f.txt'),'r');
F=fscanf(fp,'%f%f%f',[3,Inf]);
fclose(fp);
fp=fopen(strcat(folder,'labp_E.txt'),'r');
E=fscanf(fp,'%f',[1,Inf]);
fclose(fp);
X=0:dx:dx*nx;
Y=0:dy:dy*ny;
n=round(str2num(get(handles.set_N,'String')));
set(handles.energy,'String',strcat(num2str(E(n+1)),' eV'));
Z2=F(3,n*ny*nx+1:n*ny*nx+ny+1);
for(i=2:nx+1)
    Z2=[Z2;F(3,n*ny*nx+(i-1)*ny+i:n*ny*nx+i*ny+i)];
end
axes(handles.p1);
meshc(X,Y,Z2);
axis tight;
set(handles.f_save_fun,'Enable','on');
set(handles.e_fun,'Enable','on');
guidata(hObject, handles);
% hObject    handle to load_functions (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in load_potential.
function load_potential_Callback(hObject, eventdata, handles)
global nx ny dx dy X Y Z1 folder;
fp=fopen(strcat(folder,'labp_V.txt'),'r');
V=fscanf(fp,'%f%f%f',[3,Inf]);
fclose(fp);
X=0:dx:dx*nx;
Y=0:dy:dy*ny;
Z1=V(3,1:ny+1);
for(i=2:nx+1)
    Z1=[Z1;V(3,(i-1)*ny+i:i*ny+i)];
end
axes(handles.p2);
meshc(X,Y,Z1);
axis tight;
set(handles.f_save_pot,'Enable','on');
set(handles.e_pot,'Enable','on');
guidata(hObject, handles);
% hObject    handle to load_potential (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on mouse press over axes background.
function p1_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to p1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function energy_CreateFcn(hObject, eventdata, handles)
% hObject    handle to energy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --------------------------------------------------------------------
function file_Callback(hObject, eventdata, handles)
% hObject    handle to file (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function edit_Callback(hObject, eventdata, handles)
% hObject    handle to edit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function e_pot_Callback(hObject, eventdata, handles)
global X Y Z1;
f=figure;
meshc(X,Y,Z1);
axis tight;
guidata(hObject, handles);
% hObject    handle to e_pot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function e_fun_Callback(hObject, eventdata, handles)
global X Y Z2;
f=figure;
meshc(X,Y,Z2);
axis tight;
guidata(hObject, handles);
% hObject    handle to e_fun (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function f_save_pot_Callback(hObject, eventdata, handles)
global X Y Z1 folder;
filename=uiputfile('potential_plot.jpg','Save potencial plot to file');
f=figure;
meshc(X,Y,Z1);
axis tight;
saveas(f,strcat(folder,filename));
close(f);
guidata(hObject, handles);
% hObject    handle to f_save_pot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function f_save_fun_Callback(hObject, eventdata, handles)
global X Y Z2 folder;
filename=uiputfile('function_plot.jpg','Save function plot to file');
f=figure;
meshc(X,Y,Z2);
axis tight;
saveas(f,strcat(folder,filename));
close(f);
guidata(hObject, handles);
% hObject    handle to f_save_fun (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function f_open_Callback(hObject, eventdata, handles)
global dx dy N nx ny folder;
folder=uigetdir('','Chose data directory');
folder=strcat(folder,filesep);
fp3=fopen(strcat(folder,'labp_data.txt'),'r');
wx=str2num(fgetl(fp3)); set(handles.wx,'String',num2str(wx));
wy=str2num(fgetl(fp3)); set(handles.wy,'String',num2str(wy));
dT=str2num(fgetl(fp3)); set(handles.dT,'String',num2str(dT));
nx=round(str2num(fgetl(fp3))); set(handles.nx,'String',num2str(nx));
ny=round(str2num(fgetl(fp3))); set(handles.ny,'String',num2str(nx));
N=round(str2num(fgetl(fp3))); set(handles.N,'String',num2str(N));
fclose(fp3);
dx=20*wx^0.5/nx/0.0364;
dy=20*wy^0.5/ny/0.0364;
guidata(hObject, handles);
% hObject    handle to f_open (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
