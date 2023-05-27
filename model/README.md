# Motion diffusion Model
Original: <https://github.com/GuyTevet/motion-diffusion-model>

### Windows Settings
Setup Conda environment for Windows:
```
conda env create -f environment.yml
conda activate mdm
python -m spacy download en_core_web_sm
pip install git+https://github.com/openai/CLIP.git
```

**HumanML3D** - Clone HumanML3D, then copy the data dir to our repository:

```shell
cd ..
git clone https://github.com/EricGuo5513/HumanML3D.git
unzip ./HumanML3D/HumanML3D/texts.zip -d ./HumanML3D/HumanML3D/
cp -r HumanML3D/HumanML3D model/dataset/HumanML3D
cd model
```

### Download the pretrained models

Download the model(s) you wish to use, then unzip and place them in `./save/`. 
<details>
  <summary><b>Text to Motion</b></summary>
[humanml-encoder-512](https://drive.google.com/file/d/1PE0PK8e5a5j-7-Xhs5YET5U5pGh0c821/view?usp=sharing)
</details>

### Download Dependencies:
<details><summary>DOWNLOAD</summary>
<p>

Download Link: <https://drive.google.com/file/d/1R0KWIQkGus1YaL7VfsZbYhn45smKPyaJ/view?usp=sharing>
  
Unzip this as "body_models". It concludes kit, smpl, t2m folders for "Text to Motion"

</p>
</details>

### RUN server
```
python -m server.server --input_path /path/to/mp4/stick/figure/file
```