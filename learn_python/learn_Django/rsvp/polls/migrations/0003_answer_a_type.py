# -*- coding: utf-8 -*-
# Generated by Django 1.10.5 on 2017-03-01 07:27
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('polls', '0002_auto_20170301_0015'),
    ]

    operations = [
        migrations.AddField(
            model_name='answer',
            name='a_type',
            field=models.IntegerField(default=0),
        ),
    ]
