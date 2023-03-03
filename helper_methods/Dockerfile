FROM jupyter/all-spark-notebook
COPY dist /tmp/
RUN pip install /tmp/tools-0.1-py3-none-any.whl
RUN pip install pandas
RUN pip install matplotlib
