"""
请注意，若是有报错
AttributeError: 'ImageDraw' object has no attribute 'textsize'

textsize 函数在 Pillow 10 中已弃用。

因此安装 Pillow 9.5.0 将解决该问题：

pip3 install Pillow==9.5.0
"""



from stylecloud import gen_stylecloud
import jieba
import re
import random
from palettable.cartocolors.qualitative import Bold_5
# 读取数据
with open('两会金句.txt', encoding='utf-8') as f:
    data = f.read()

# 文本预处理  去除一些无用的字符   只提取出中文出来
new_data = re.findall('[\u4e00-\u9fa5]+', data, re.S)
new_data = "/".join(new_data)

# 文本分词
seg_list_exact = jieba.cut(new_data, cut_all=True)

result_list = []
with open('中文常用停用词.txt', encoding='utf-8') as f:
    con = f.readlines()
    stop_words = set()
    for i in con:
        i = i.replace("\n", "")   # 去掉读取每一行数据的\n
        stop_words.add(i)

for word in seg_list_exact:
    # 设置停用词并去除单个词
    if word not in stop_words and len(word) > 1:
        result_list.append(word)
print(result_list)

# 个人推荐使用的palette配色方案  效果挺好看
# colorbrewer.qualitative.Dark2_7
# cartocolors.qualitative.Bold_5
# colorbrewer.qualitative.Set1_8

gen_stylecloud(
    text=' '.join(result_list),               # 文本数据
    size=512,                                 # 词云图大小
    font_path=r'C:\\Windows\\Fonts\\msyh.ttc',   # 中文词云  显示需要设置字体
    output_name='词云图.png',                   # 输出词云图名称
    icon_name='fas fa-apple-alt',             # 图标
    palette='cartocolors.qualitative.Bold_5'  # 设置配色方案
)

""" gen_stylecloud的使用方法
gen_stylecloud(text=None,            #输入字体
                   file_path=None,   # 输入文本/CSV 的文件路径
                   gradient=None,    #渐变方向（梯度方向），默认是horizontal
                   size=512,         # stylecloud 的大小（长度和宽度,调大可以提高图片的清晰度）
                   icon_name='fas fa-flag',  # stylecloud 形状的图标名称（如 fas fa-grin）。[default: fas fa-flag]
                   palette='cartocolors.qualitative.Bold_5',  # 调色板（通过 palettable 实现）。[default: cartocolors.qualitative.Bold_6]
                   colors=None,     #文本颜色
                   background_color="white",  # 背景颜色
                   max_font_size=200,  # stylecloud 中的最大字号
                   max_words=2000,  # stylecloud 可包含的最大单词数
                   stopwords=True,  # 布尔值，用于筛除常见禁用词
                   custom_stopwords=STOPWORDS,#list定制停用词列表
                   icon_dir='.temp',
                   output_name='stylecloud.png',   # stylecloud 的输出文本名
                   font_path=os.path.join(STATIC_PATH,
                                          'Staatliches-Regular.ttf'), # stylecloud 所用字体
                   random_state=None,  # 控制单词和颜色的随机状态
                   collocations=True,#是否包括两个单词的搭配
                   invert_mask=False,#是否反转图标掩码
                   pro_icon_path=None,
                   pro_css_path=None)

 """
